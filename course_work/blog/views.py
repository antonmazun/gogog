from django.shortcuts import render
from django.http.response import HttpResponse , Http404
from django.template.loader import get_template #получение шаблона
from django.template import Context
from django.shortcuts import render_to_response ,redirect
from .models import Products,Phone,Comments , Category
from django.core.exceptions import ObjectDoesNotExist
from django.contrib import auth
import django
from django.http import HttpResponseRedirect
from django.contrib.auth.decorators import login_required
from django.template import loader, RequestContext
from django.contrib.auth.models import User
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from django.contrib.auth.forms import UserCreationForm
import  json ,sys
#from .forms import CommentsForm
#from django.views.decorators import csrf
# Create your views here.

from django.contrib.auth.forms import UserCreationForm

def basic_one(request):
    view = "basic_one"
    html = "index.html"

    return HttpResponse(html)

def template_two(request):
    view = "tempalte_two"
    t = get_template("index.html" , using= None)
    html = t.render(Context({'name':view}))
    return HttpResponse(html)


def template_three(request):
    view = "template_3"
    return render_to_response("index.html" , {'name' : view})


def zakaz(request):
    args= {}
    if request.method == "GET":
        args['user'] = request.user
        args['form'] = UserCreationForm
        args['username'] = request.user.username

    elif request.method == "DELETE":
        try:
            #user = User.phones.get(id = int(request.GET['phone']))
            User.phones.through.objects.get(phone_id= int(request.GET['phone']), user_id=request.user.id).delete()
        except:
            print(sys.exc_info())
            return  HttpResponse(json.dumps({"status": "error"}) , content_type = "application/json")
        return HttpResponse(json.dumps({"status": "ok"}), content_type="application/json")

    return render(request , 'zakaz.html' , args)




def phones_view(request):

    if request.is_ajax():
        user = request.user
        if not user.is_authenticated():
          return HttpResponse(json.dumps({"status": "please authenticated"}), content_type = "application/javascript")
        try:
            user.phones.add(Phone.objects.get(id = int(request.POST['add'])))
        except:
            print(sys.exc_info())
            return HttpResponse(json.dumps({"status": "error"}), content_type="application/javascript")
        print(Phone.objects.get(id = int(request.POST['add'])).title)
        return HttpResponse(json.dumps({"status":"ok"}) , content_type = "application/javascript")

    phone_list = Phone.objects.all()
    paginator = Paginator(phone_list, 6)
    page = request.GET.get('page')
    try:
        phones = paginator.page(page)
    except PageNotAnInteger:
        phones = paginator.page(1)
    except EmptyPage:
        phones = paginator.page(paginator.num_pages)

    return render_to_response("phones_view.html" , { 'form' : UserCreationForm , 'phones': phones , 'username' : auth.get_user(request).username})



def phone_view(request, path):

    args = {}
    args['form'] = UserCreationForm
    if request.method == 'GET':

        return render_to_response("phone.html" , {'form' : UserCreationForm , 'phone': Phone.objects.get(id = int(path)) ,'username' : request.user.username, 'comments':Phone.objects.get(id = int(path)).comments.all()})

    elif request.method == 'POST' and request.POST['text'] and request.user.is_authenticated():
        error = False
        if request.session.get('has_commented_already', False):
            error = "You have already commented this post!"
        else:
            Comments.objects.create(comments = request.POST['text'] , creator = request.user , phone = Phone.objects.get(id = int(path)))
            request.session['has_commented_already'] = True

        return render_to_response("phone.html", {'form' : UserCreationForm , 'error': error , 'phone': Phone.objects.get(id=int(path)) , 'username' : request.user.username, 'comments':Phone.objects.get(id = int(path)).comments.all()})
    elif  request.method == 'POST' and request.POST['text'] and not request.user.is_authenticated():
        return redirect('/auth/login/')
    else:
        return render_to_response("phone.html" , {'form' : UserCreationForm , 'phone' : Phone.objects.get(id = int(path))})




def search(request):
        if request.user.is_authenticated():
            username = request.user
        else:
            username = None
        phones = Phone.objects.none()
        flag = True
        print(phones)
        if 'search' in request.GET:
            search = request.GET['search'].split()
            print(search)
            for val in search:
                if flag:
                    newphones = Phone.objects.filter(title__icontains=val)
                    print(newphones)
                    if newphones:
                        phones = newphones
                    else:
                        continue
                    flag = False
                else:
                    newphones = phones & Phone.objects.filter(title__icontains=val)
                    if newphones:
                        phones = newphones

        return HttpResponse(json.dumps([i.dic() for i in phones]) , content_type = "application/javascript")

        #return render(request, "search.html", {'form' : UserCreationForm  ,  'phones': phones, 'username': username})



        # try:
        #     if path in request.COOKIES:
        #            redirect('/')
        #     else:
        #          phones = Phone.objects.get(id=int(path))
        #          phones.likes += 1
        #          phones.save()
        #          response = redirect('/')
        #          response.set_cookie(path , "test")
        #          return response
        # except ObjectDoesNotExist:
        #     raise Http404





'''
def comments_view(request , path):
    comments_form  = CommentsForm
    args = {}
    args.update(csrf(request))
    args['comments'] = Phone.objects.get(id = int(path))
    args['created_date'] = Comments.objects.filter(id = int(id()))
    args['likes' ] = comments_form
    return render_to_response("phone.html" , args)


'''

def show_category(request):
    return render( request , "category.html")


