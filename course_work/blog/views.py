from django.shortcuts import render
from django.http.response import HttpResponse , Http404
from django.template.loader import get_template #получение шаблона
from django.template import Context
from django.shortcuts import render_to_response ,redirect
from .models import Products,Phone,Comments , Category
from django.core.exceptions import ObjectDoesNotExist
from django.contrib import auth
from django.http import HttpResponseRedirect
from django.contrib.auth.decorators import login_required
from django.template import loader, RequestContext
from django.contrib.auth.models import User
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


def phones_view(request):

    return render_to_response("phones_view.html" , {'phones': Phone.objects.all() , 'username' : auth.get_user(request).username})


def phone_view(request, path):

    args = {}
    args['form'] = UserCreationForm
    if request.method == 'GET':

        return render_to_response("phone.html" , {'phone': Phone.objects.get(id = int(path)) ,'username' : request.user.username, 'comments':Phone.objects.get(id = int(path)).comments.all()})

    elif request.method == 'POST' and request.POST['text'] and request.user.is_authenticated():
        error = False
        if request.session.get('has_commented_already', False):
            error = "You have already commented this post!"
        else:
            Comments.objects.create(comments = request.POST['text'] , creator = request.user , phone = Phone.objects.get(id = int(path)))
            request.session['has_commented_already'] = True

        return render_to_response("phone.html", {'error': error , 'phone': Phone.objects.get(id=int(path)) , 'username' : request.user.username, 'comments':Phone.objects.get(id = int(path)).comments.all()})
    elif  request.method == 'POST' and request.POST['text'] and not request.user.is_authenticated():
        return redirect('/auth/login/')
    else:
        return render_to_response("phone.html" , {'phone' : Phone.objects.get(id = int(path))})



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


