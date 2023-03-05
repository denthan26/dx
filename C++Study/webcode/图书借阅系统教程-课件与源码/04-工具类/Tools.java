package com.sxt.utils;

import java.util.List;

/**
 *   	集合转数组
 * @author NINGMEI
 *
 */
public class Tools {

	public static Object[] listToArr(List<Object> list) {
		int size = list.size();
		if (size == 0) {
			return new Object[0];
		}
		Object[] arr = new Object[size];
		for (int i = 0; i < list.size(); i++) {
			arr[i] = list.get(i);
		}
		return arr;
	}
	
}
