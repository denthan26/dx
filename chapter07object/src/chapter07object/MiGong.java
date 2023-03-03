package chapter07object;

public class MiGong {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//new 数组map
		int[][] map = new int[8][7];
		
		//四周为1
		for(int i = 0; i < 7; i++) {
			map[0][i] = 1;
			map[7][i] = 1;
		}
		
		for(int i = 0; i < 8; i++) {
			map[i][0] = 1;
			map[i][6] = 1;
		}
		map[3][1]=1;
		map[3][2]=1;
		// 输出数组
		System.out.println("寻路前的迷宫");
		for(int i = 0; i < map.length; i++) {
			for(int j = 0; j < map[i].length; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		
		//使用findWay找路
		T t1 = new T();
		t1.findWay(map, 1, 1);
		
		System.out.println("寻路后的迷宫");
		for(int i = 0; i < map.length; i++) {
			for(int j = 0; j < map[i].length; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}

	}

}

class T {
	//使用递归回溯的思想
	//找到路返回true，否则返回false
	//i,j就是老鼠，初始化位置（1，1）
	//因为递归找路，规则
	//0可走，1不可走，2表示可以走，3表示可以走，但是死路
	public boolean findWay(int[][] map, int i, int j) {
		if(map[6][5] == 2) {
			return true;
		} else {
			if(map[i][j] == 0) {
				map[i][j] = 2;
				if(findWay(map, i + 1, j)) {
					return true;
				}else if(findWay(map, i, j + 1)){
					return true;
				}else if(findWay(map, i - 1, j)) {
					return true;
				}else if(findWay(map, i, j - 1)) {
					return true;
				}else {
					map[i][j] = 3;
					return false;
				}
			}else {
				return false;
			}
		}
	}
}
