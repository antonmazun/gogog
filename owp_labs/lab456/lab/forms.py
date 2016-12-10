from django import forms

class UploadFileForm(forms.Form):
    title = forms.CharField(max_length=50)
    image = forms.ImageField()

class PhoneForm(forms.Form):
    image = forms.ImageField()