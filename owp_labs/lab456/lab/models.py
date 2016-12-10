from django.db import models

# Create your models here.
class Phone(models.Model):

    name = models.CharField(max_length = 200)
    manufacturer = models.TextField()
    price = models.IntegerField()
    rate = models.FloatField()
    date = models.DateField()
    image = models.ImageField(upload_to= 'image/' ,null = True)


    def dic(self):
        return {'name':self.name ,
                'manufacturer': self.manufacturer ,
                'price':self.price ,
                'rate' : self.rate,
               # 'image' :self.image.url,}
                }