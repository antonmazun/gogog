from django.contrib import admin
from .models import Phone

class PhoneAdmin(admin.ModelAdmin):
    fields = ['name' , 'manufacturer', 'price' , 'rate', 'date' , 'image']



admin.site.register(Phone , PhoneAdmin)


# Register your models here.
