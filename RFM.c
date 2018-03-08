double ftn(double x)
{
	return(x*x*x*x+2*x*x*x-13*x*x-14*x+24);
}

void RFM()
{

	double dx=1e-1,err=1e-7;
	double a,b,c,x;
	int num;
	printf("     a   \t   b    \t\t    c    \t\t  ftn(a)  \t  ftn(b)  \t  ftn(c)   iterations\n");

	for(x=-5.;x<=5.;x+=2*dx)
	{
		if(ftn(x-dx)*ftn(x+dx)<0.)
		{
			a=x-dx;
			b=x+dx;
			num=0;

			while(1)
			{
				c=(a*ftn(b)-b*ftn(a))/(ftn(b)-ftn(a));
				if(fabs(a-c)<err || fabs(b-c)<err) break;
		
				if(num<20) printf("%d %+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf \n",num,a,b,c,ftn(a),ftn(b),ftn(c));

				if(ftn(c)*ftn(b)<=0) a=c;
				if(ftn(a)*ftn(c)<=0) b=c;

				num++;
			}
			printf("%d %+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf \n",num,a,b,c,ftn(a),ftn(b),ftn(c));
		}
	}
}
				
