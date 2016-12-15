from django.conf.urls import url
from . import views


urlpatterns = (

    url(r'^1/' ,views.basic_one),
    url(r'^2/' ,views.template_two),
    url(r'^3/' , views.template_three),
    url(r'^$', views.phones_view),
    url(r'^phones_view/get/(\d+)/$' , views.phone_view),
    url(r'^category/$', views.show_category),
    url(r'^search/', views.search),
    url(r'^zakaz/get/$' , views.zakaz),
)