
double ternary()
{
    leftt=0; rightt=n;
    while(rightt-leftt>100)
    {
        blck=(rightt-leftt)/3;
        m1=leftt+blck; m2=leftt+2*blck;
        //cout<<"f(m1) = "<<f(m1)<<" f(m2) = "<<f(m2)<<endl;
        if(f(m1)>=f(m2))leftt=m1;
        else rightt=m2;
    }
    double last=1e9;
    for(int i=leftt;i<=rightt;i++)last=min(last,f(i));
    return last;
}
