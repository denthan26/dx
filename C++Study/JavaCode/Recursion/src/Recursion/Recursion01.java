package Recursion;

public class Recursion01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		T t1 = new T();
		t1.test(4);
		int res = t1.factorial(6);
		System.out.println(res);
		res = t1.faboniacc(7);
		if(res==-1) {
			System.out.println("数字错了");
		}else {
			System.out.println(t1.faboniacc(7));
		}
	}

}
class T {
	public void test(int n) {
		if(n>2) {
			test(n-1);
		}
		System.out.println("n="+ n);
	}
	
	public int factorial(int n) {
		if(n==1) {
			return 1;
		}else {
			return factorial(n-1)*n;
		}
		
	}
	public int faboniacc(int n) {
		if(n<1) {
			return -1;
		}
		if(n==1||n==2) {
			return 1;
		}else {
			return faboniacc(n-1) + faboniacc(n-2);
		}
		
	}
}