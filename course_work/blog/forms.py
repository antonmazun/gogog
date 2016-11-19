

from django.forms import ModelForm
from .models import Comments

class CommentsForm(ModelForm):

    model = Comments

