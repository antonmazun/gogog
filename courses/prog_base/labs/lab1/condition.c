
#import <math.h>

int satisfies(int a, int b, int c)
{
	int result, max, min;
	double modmin;
	int sum2;


	if (a < 0 && b < 0 && c < 0)
	{

		if (a <= b && a <= c)
		{
			modmin = abs(a);
			sum2 = b + c;
		}
		else
		{
			if (b <= c && b <= a)
			{
				modmin =  abs (b);
				sum2 = a + c;
			}
			else
			{
				modmin = abs( c) ;
				sum2 = a + b;
			}
		}

		if (sum2 < -256 && fmod(log2(modmin), 1) == 0 && modmin <= 256)
		{
			return 1;
		}
		else

		{
			if (abs(sum2 - modmin) < 16 || abs(sum2) < 16)
				return 1;
		}
	}
	else
	{
		if (a < 0 && b > 0 && c > 0)
		{
			if (a > -256)
				return 1;
			else
				return 0;
		}
		else
		{
			if (b < 0 && a >0 && c > 0)
			{
				if (b < -256)
					return 1;
				else
					return 0;
			}
			else
			{
				if (c < 0 && a >= 0 && b >= 0)
				{
					if (c < -256)
						return 1;
					else
						return 0;
				}
				else
				{
					if (a < 0 && b < 0 && c > 0)
					{
						if ((a + b) * 3 > -256)
							return 1;
						else
							return 0;
					}
					else
					{
						if (a < 0 && c < 0 && b > 0)
						{
							if ((a + c) * 3 > -256)
								return 1;
							else
								return 0;
						}
						else
						{
							if (b < 0 && c < 0 && a > 0)
							{
								if ((b + c) * 3 > -256)
									return 1;
								else
									return 0;
							}
							else
							{
								if (a > b && b > c)
								{
									max = a;
									min = c;
								}
								else {
									if (b > a && a > c)
										{
										max = b;
										min = c;
											
										}
									else {
										if (c > b && b > a)
										{
											max = c;
											min = a;
										}
										else {
											if (b > c && c > a)
											{
												max = b;
												min = a;
											}
											else {

												if (a > c && c > b)
												{
													max = a;
													min = b;
												}
												else {

													if (c > a && a > b)
													{
														max = c;
														min = b;
													}
													}

												}
											}
										}

									}
								
									}
								if (max * min < 256)
									return 1;
								else 
									return 0;
							}
						}

					}

				}
			}
		}

	}

				}
			}
		}
	}
	return 0;
}
