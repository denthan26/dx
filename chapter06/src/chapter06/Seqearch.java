package chapter06;

import java.util.Scanner;

public class Seqearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner myScanner = new Scanner(System.in);
		String[] names = {"白美食网","经贸失望","是你大哥"};
		String findName = myScanner.next();
		int i;
		for(i = 0; i<names.length;i++)
		{
			if(findName.equals(names[i])){
				System.out.println("恭喜你找到了");
				System.out.println("下表为"+i);
				break;
			}
		}
		if(i>=names.length)
		{
			System.out.println("没找到");
		}
		
		
		myScanner.close();
	}

}
