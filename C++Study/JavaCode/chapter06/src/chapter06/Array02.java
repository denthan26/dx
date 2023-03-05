package chapter06;

import java.util.Scanner;

public class Array02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		Scanner myScanner = new Scanner(System.in);
		System.out.println("input numbers:");
		n = myScanner.nextInt();
		double[] nums = new double[n];
		for(int i = 0;i < nums.length;i++)
		{
			System.out.println("Input " + i + "number:");
			nums[i]=myScanner.nextInt();
		}
		
		for(int i = 0;i<nums.length;i++)
		{
			System.out.println(i + " number:" + nums[i]);
		}
		char[] chars = new char[2];
		chars[0]='A'+1;
		
		myScanner.close();
	}

}
