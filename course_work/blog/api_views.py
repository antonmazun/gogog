from django.contrib import auth
from django.shortcuts import render
from django.shortcuts import render_to_response ,redirect , HttpResponse #render
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm
from django.http.response import HttpResponse , Http404
from django.template import Context
from .models import Products,Phone,Comments , Category
# Create your views here.
import json


def register(request):
     args = {}
     args['form'] = UserCreationForm
     if request.POST:
         newuser_form  =  UserCreationForm(request.POST)
         if newuser_form.is_valid():
             newuser_form.save()
             newuser = auth.authenticate(username = newuser_form.cleaned_data['username'] , password  = newuser_form.cleaned_data['password2'])
             auth.login(request , newuser)
             newuser.save()
             print(newuser)
             return HttpResponse(json.dumps({'signup':'ok'}) , content_type="application/json")
         else:
             args['form'] =  newuser_form
             return HttpResponse(json.dumps({'signup': 'ne ok'}), content_type="application/json")






def login(request):
    args = {}
    if request.POST:
        username = request.POST.get('username'  , '')
        password = request.POST.get('password' , '')
        user = auth.authenticate(username=username , password=password)
        print(username)
        print(password)
        if user is not None and user.is_active:
            auth.login(request , user)
            return redirect('/')
        else:
            args['login_error'] = "User is not found"
            return HttpResponse(request , 'login.html' , args)
    else:
        return HttpResponse( request , 'login.html', args)



def logout(request):
    auth.logout(request)
    return redirect('/')



def phones_view(request):
    f = Phone.objects.all()
    response_data = [i.dic() for i in f]
    return HttpResponse(json.dumps({'phones': response_data}), content_type="application/json")

def phone_view(request, path):

    args = {}
    args['form'] = UserCreationForm

    if request.method == 'GET':
        f = Phone.objects.get(id=int(path)).comments.all()
        response_data = [i.dic() for i in f]
        return HttpResponse(json.dumps({'phone': response_data}) , content_type = "application/json")

    elif request.method == 'POST' and request.POST['text'] and request.user.is_authenticated():
        error = False
        if request.session.get('has_commented_already', False):
            error = "You have already commented this post!"
        else:
            Comments.objects.create(comments = request.POST['text'] , creator = request.user , phone = Phone.objects.get(id = int(path)))
            request.session['has_commented_already'] = True

        return HttpResponse("phone.html", {'error': error , 'phone': Phone.objects.get(id=int(path)) , 'username' : request.user.username, 'comments':Phone.objects.get(id = int(path)).comments.all()})
    elif  request.method == 'POST' and request.POST['text'] and not request.user.is_authenticated():
        return render(request, "register.html", args)
    else:
        return HttpResponse("phone.html" , {'phone' : Phone.objects.get(id = int(path))})



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


