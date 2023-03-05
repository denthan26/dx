package chapter07object;

public class Object01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat cat1 = new Cat();
		cat1.age = 10;
		cat1.color = "白色";
		cat1.name = "小白";
		Cat cat2 = new Cat();
		cat2.age = 100;
		cat2.color = "花色";
		cat2.name = "小米";
		System.out.println("第一只猫的信息："+ cat1.name + " "
				+ cat1.age + " " + cat1.color);
		System.out.println("第一只猫的信息："+ cat2.name + " "
				+ cat2.age + " " + cat2.color);
		
		String abe="1";
		System.out.println(abe);
	}

}
class Cat{
	String name;
	int age;
	String color;
}