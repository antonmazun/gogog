from django.db import models
from django.utils import timezone
from django.contrib.auth.models import User
#from ckeditor_uploader.fields import RichTextUploadingField
from mptt.models import MPTTModel , TreeForeignKey

# Create your models here.
class Category(MPTTModel):
    verbose_name_plural = "Category"
    verbose_name = "Category"
    ordering = ('tree_id' , 'level')
    name = models.CharField(max_length=150 , verbose_name = "Category")
    parent = TreeForeignKey('self' , null=True , blank  = True , related_name="children" , db_index = True)
    def __unicode__(self):
        return self.name

    def __str__(self):
        return self.name

    class MPTTMeta:
        order_insertion_py = ['name']
#mppt.register(Category , order_insertion_py = ['name'])



class Products(models.Model):


    title = models.CharField(max_length=300)
    desc = models.TextField()
    created_date = models.DateTimeField(default=timezone.now)
    likes = models.IntegerField(default=0)
   # model_pic = models.ImageField(null = True , blank = True ,upload_to='images/', verbose_name= "Изображение")

    def dic(self):
        return {'title' : self.title ,
                'desc': self.desc ,
                'likes':self.likes}

    def publish(self):
        self.published_date = timezone.now()
        self.save()

    def __str__(self):
        return self.title


class Comments(models.Model):
    comments = models.TextField()
    created_date = models.DateTimeField(default=timezone.now)
    likes = models.IntegerField(default=0)
    phone  = models.ForeignKey('Phone' , on_delete=models.CASCADE , related_name= 'comments' , default= None)
    creator = models.ForeignKey(User , on_delete=models.CASCADE , related_name= 'comments' , default= None)

    def dic(self):
        return {'comments': self.comments,
                'likes': self.likes,
                }

class Phone(models.Model):

    title = models.CharField(max_length = 200)
    desc = models.TextField()
    price = models.IntegerField()
    rate = models.FloatField()
    date = models.DateField()
    likes = models.IntegerField(default=0)
    image = models.ImageField(upload_to= 'image/' ,null = True)
    category = TreeForeignKey(Category , blank=True , null = True  , related_name='iphone')
    quantity = models.IntegerField(default= 10)


    def dic(self):
        return {'title':self.title ,
                'desc': self.desc ,
                'price':self.price ,
                'rate' : self.rate ,
                'likes': self.likes,
                'quantity':self.quantity}

    def __str__(self):
        return (self.title)

