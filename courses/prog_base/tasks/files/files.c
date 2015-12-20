void fprocess(const char * pread, const char * pwrite)
{
	FILE * a = NULL;
	FILE * b = NULL;
	a = fopen(pread, "r");
	b = fopen(pwrite, "w");
	if (NULL == a)
		return;
	if(NULL == b)
	
		return;
		
	int i = 0, a1 = 0 , c = 0;
	for(i = 0; i < 11; i++)
		while (fgetc(a) != 10)
			;
			c = i * j;
	fscanf(a, "%i %i", &i,&j);
		c = i * j;
	fprintf(b, "%i", c);
	fclose (b);
	fclose (a);
}
