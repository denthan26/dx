package chapter07object;

public class Eightqueens {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//完成八皇后
		int[][] map = new int[8][8];
		for(int i = 0; i < map.length; i++) {
			for(int j = 0; j < map[i].length; j++) {
				map[i][j] = 0;
			}
		}
		map[0][0] = 1;
		System.out.println("进行处理前的棋盘");
		for(int i = 0; i < map.length; i++) {
			for(int j = 0; j < map[i].length; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		EightQ q = new EightQ();
		q.find(map);
		System.out.println("进行处理后的棋盘");
		for(int i = 0; i < map.length; i++) {
			for(int j = 0; j < map[i].length; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}
class EightQ {
	public void find(int[][] map){
		//给一个8x8的棋盘，第一颗棋子固定在（0，0）
		//第二颗棋子与第一颗棋子一致
		//重复，直到八颗棋子都存在
		//可以放棋子置为1
		for(int i = 1; i < map.length; i++) {
			for(int j = 0; j < map[i].length; j++) {
				map[i][j] = 1;
				if(!isPlease(map, i, j)) {
					map[i][j] = 0;
				}
				break;
			}
		}
		
	}
	
	public boolean isPlease(int[][] map, int row, int col) {
		//这一步在row行，col列放置，判断row行或col是否存在元素，存在返回false，
		//再判断row==col，相等返回false
		if(row == col) {
			return false;
		}
		//判断row行是否存在元素
		for(int i = 0; i < map[row].length; i++) {
			if(map[row][i] == map[row][col]) {
				if( i == col) {
					continue;
				}else {
					return false;
				}
			}
		}
		//判断col列是否存在元素
		for(int i = 0; i < map.length; i++) {
			
			if(map[i][col] == map[row][col]) {
				if(i == row) {
					continue;
				}else {
					return false;
				}
			}
		}
		return true;
	}
}
