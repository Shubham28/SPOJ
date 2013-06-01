import java.math.*;
import java.io.DataInputStream;
import java.io.InputStream;

public class Main
{
	public static void main(String args[])
	{
		try
		{
			StringBuffer outpt=new StringBuffer(4000000);
			long[] seq=new long[2];
			seq[0]=1;

			int loop,ch=0;
			for(loop=1;loop<=350250;loop++)
			{
				BigInteger val=BigInteger.valueOf(seq[ch]);
				if(val.isProbablePrime(1))
					outpt.append('1');
				else
					outpt.append('0');

				seq[ch^1]=(seq[ch]+1234567890)%(1<<31);
				ch^=1;
			}

			System.out.print(outpt.toString());
		}
	catch(Exception e){}
	}
}
