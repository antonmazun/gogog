void fprocess(const char * pread, const char * pwrite)
{
	FILE * fr = NULL;
	FILE * fw = NULL;
	fr = fopen(pread, "r");
	fw = fopen(pwrite, "w");
	char ch;
	if (fr == NULL || fw == NULL)
		return;
	int a = 0, a1 = 0;
	for(a = 0; a < 11; a++)
		while (fgetc(fr) != 10)
			;
	fscanf(fr, "%i %i", &a, &a1);
	fprintf(fw, "%i", a * a1);
	fclose (fw);
	fclose (fr);
}
