from django.conf.urls import url , include

from django.contrib import admin
from . import api_views

urlpatterns = (


    url(r'^$', api_views.phones_view),
    url(r'^phone/(\d+)/$' , api_views.phone_view),
    url(r'^phones_view/get/(\d+)/$' , api_views.phone_view),
    url(r'^category/$', api_views.show_category),
    url(r'^login/$', api_views.login),
    url(r'^logout/$', api_views.logout),
    url(r'^register/$', api_views.register),
    url(r'^admin/', include(admin.site.urls)),
    url(r'^basicview/', include('blog.urls')),
    url(r'^auth/', include('loginsys.urls')),
    url(r'^', include('blog.urls')),

)