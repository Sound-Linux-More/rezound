
static const char playMouseCursorSource[]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,
	0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,
	0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,
	0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,
	0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,
	0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,
	0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,
	0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,
	0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,
	0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,
	0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,
	0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

static const char playMouseCursorMask[]={
	0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,
	0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,
	0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,
	0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,
	0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,
	0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,
	0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,
	0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,
	0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,
	0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,
	0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,
	0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,
	0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,
	0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,
	0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,
	0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,
};


static void *bytesToBits(const char *bytes,int bytesLength)
{
	char *bits=new char[(bytesLength/8)+1];
	for(int t=0;t<bytesLength/8+1;t++)
		bits[t]=0; 
	for(int t=0;t<bytesLength;t++)
	{
		if(bytes[t])
			bits[t/8]|=(1<<(t%8));
	}

	return bits;
}


