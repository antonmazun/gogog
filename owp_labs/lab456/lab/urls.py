"""labs URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.10/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.conf.urls import url, include
    2. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import url

from . import views

urlpatterns = [

    url(r'^show/$'  ,views.phones_view),
    url(r'^phones_view/get/(\d+)/$', views.phone_view),
    url(r'^phone_delete/get/(\d+)/$' , views.phone_del),
    url(r'^search/', views.search),
    url(r'^interesting/$' , views.interesting),
    url(r'^users/$' , views.view_users),
    url(r'^$', views.show),

]