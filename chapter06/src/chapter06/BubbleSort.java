package chapter06;

public class BubbleSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = {12,24,11,32,2,5};
		System.out.println("未排序之前：");
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+"\t");
		}
		for(int i = 0;i<arr.length-1;i++) {
			for(int j = 0;j < arr.length-1-i;j++) {
				if(arr[j]>arr[j+1])
				{
					int temp = arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		System.out.println("排序之后：");
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+"\t");
		}
		arr.clone();
	}

}
