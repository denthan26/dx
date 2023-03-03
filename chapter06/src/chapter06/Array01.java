package chapter06;

public class Array01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double[] hens = {3,5,4,3.2,6};
		double total=0;
		for(int i=0;i<hens.length;i++)
		{
			total+=hens[i];
		}
		System.out.println(total / hens.length);
	}

}
