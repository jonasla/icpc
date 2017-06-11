double epsilon = 1e-15;

double f (double x1, double y1, double x2, double y2, double t)
{
	return (x1+t*(x2-x1))*(x1+t*(x2-x1)) + (y1+t*(y2-y1))*(y1+t*(y2-y1));
}

double maxiTernarySearch (double x1,double y1, double x2,double y2)
{
	double tLeft = 0;
	double tRight = 1;
	while (abs(tRight - tLeft) > epsilon)
	{
		double tLeftThird  = (2.0*tLeft + tRight)/3.0;
		double tRightThird = (tLeft + 2.0*tRight)/3.0;
		if (f(x1,y1,x2,y2,tLeftThird) < f(x1,y1,x2,y2,tRightThird))
			tLeft = tLeftThird;
		else
			tRight = tRightThird;
			
		
			
	}
	return f(x1,y1,x2,y2,(tLeft+tRight)/2.0);
}

double miniTernarySearch (double x1,double y1, double x2,double y2)
{
	double tLeft = 0;
	double tRight = 1;
	while (abs(tRight - tLeft) > epsilon)
	{
		double tLeftThird  = (2.0*tLeft + tRight)/3.0;
		double tRightThird = (tLeft + 2.0*tRight)/3.0;
		if (f(x1,y1,x2,y2,tLeftThird) > f(x1,y1,x2,y2,tRightThird))
			tLeft = tLeftThird;
		else
			tRight = tRightThird;
			
	}
	return f(x1,y1,x2,y2,(tLeft+tRight)/2.0);
}

tint miniTernarySearch (vector<tint> &a,vector<tint> &b, tint kMin, tint kMax)
{
	tint kLeft = kMin, kRight = kMax;
	while (abs(kRight - kLeft) > 5)
	{
		tint kLeftThird  = (2*kLeft + kRight)/3;
		tint kRightThird = (kLeft + 2*kRight)/3;
		if (f(kLeftThird,a,b) > f(kRightThird,a,b))
			kLeft = kLeftThird;
		else
			kRight = kRightThird;
			
	}
	tint ans = 1e16;
	forsn(k,kLeft,kRight+1)
		ans = min(ans,f(k,a,b));
	return ans;
}

tint miniTernarySearch (tint a, tint b) // E [a,b] esta el minimo
{
	tint l = a, r = b;
	while (abs(r - l) > 3)
	{
		tint al = (2*l + r)/3;
		tint br = (l + 2*r)/3;
		if (f(al) > f(br))
			l = al;
		else
			r = br;
			
	}
	tint ans = 1e16;
	forsn(k,l,r+1)
		ans = min(ans,f(k));
	return ans;
}
