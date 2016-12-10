from django.conf.urls import url , include

from django.contrib import admin
from . import api_views

urlpatterns = (



    url(r'^phone_add/$', api_views.phones_view_api),
    url(r'^phone_del/(\d+)/$', api_views.phone_del_api),
    url(r'^$', api_views.phones_view),


)