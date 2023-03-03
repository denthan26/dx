package chapter07object;

public class HanoiTower {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tower t1 = new Tower();
		t1.move(160, 'A', 'B', 'C');
	}

}
class Tower {
	public void move(int num, char a, char b, char c) {
		if(num == 1) {
			System.out.println(a + "->" + c);
		}else {
			move(num - 1, a, c, b);
			System.out.println(a + "->" + c);
			move(num - 1, b, a, c);
		}
	}
}