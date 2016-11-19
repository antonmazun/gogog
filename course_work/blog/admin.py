from django.contrib import admin
# Register your models here.
from .models import Products
from .models import Phone , Category
from mptt.admin import MPTTModelAdmin

#from .models import Comments
#from .forms import CommentsForm


class ProductsAdmin(admin.ModelAdmin):
    fields = ['title' , 'desc', 'created_date' ]
    list_filter = ['created_date']

class PhoneAdmin(admin.ModelAdmin):
    fields = ['title' , 'desc', 'price' , 'rate', 'date' , 'image' ]
   # list_filter = ['price']

class CategoryAdmin(admin.ModelAdmin):
    fields = [ 'name' , 'parent']

'''
class CommentsAdmin(admin.ModelAdmin):

     fields  = ['comments' , 'created_date' , 'likes']

'''

admin.site.register(Products , ProductsAdmin)
admin.site.register(Phone , PhoneAdmin)
admin.site.register(Category , CategoryAdmin)
#admin.site.register(Comments , CommentsAdmin)
#admin.site.register(PhoneAdmin)