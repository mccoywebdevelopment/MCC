import java.util.Scanner;
public class HomeWork1 {

	public static void main(String[] args) {
		Scanner kb=new Scanner(System.in);
		final double Murray = 5.0/7.0;
		double frequency,TotalFreq,power;
		int cyberverns,i;
		System.out.println("Welcome to cybervern calc.");
		System.out.println("Please enter the number"
				+ "of cyberverns.");
		do
		{
			cyberverns=kb.nextInt();
			if(cyberverns<0)
			{
				System.out.println("Enter a positive #.");
			}
		}while(cyberverns<0);
		TotalFreq=0;
		for(i=0;i<cyberverns;++i)
		{
			System.out.println("Enter frequency.");
			do
			{
			frequency=kb.nextDouble();
				if(frequency<0)
				{
					System.out.println("Enter a positive #.");
				}
			}while(frequency<0);
			TotalFreq=TotalFreq+frequency;
		}
		
		power=Murray*Math.PI*Math.pow(TotalFreq, 4);
		System.out.println(power);
}
}
