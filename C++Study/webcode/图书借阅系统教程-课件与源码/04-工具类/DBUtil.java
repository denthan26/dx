package com.sxt.utils;

import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;
import java.util.Properties;

public class DBUtil {
	private static String username;
	private static String password;
	private static String url;
	private static String driver;
	

	private static Connection conn = null;
	private static PreparedStatement pstmt = null;
	private static  ResultSet  rs=null;
	
	
	static{
		Properties prop = new Properties();
		InputStream is = DBUtil.class.getClassLoader().getResourceAsStream("database.properties");
		try {
			prop.load(is);
			if(prop != null){
				username = prop.getProperty("username");
				password = prop.getProperty("password");
				url = prop.getProperty("url");
				driver = prop.getProperty("driver");
				Class.forName(driver);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	
	public static Connection getConnection(){
		Connection conn = null;
		try {
			conn = DriverManager.getConnection(url, username, password);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return conn;
	}
	
	/**
	 * 执行insert、update、delete 三个DML操作
	 * @param sql
	 * @param prams
	 * @return
	 */
	public static int executeUpdate(String sql, Object[] params) {
		
		conn = getConnection();
		int n = 0;
		try {
			pstmt = conn.prepareStatement(sql);
			if (params != null) {
				for (int i = 0; i < params.length; i++) {
					pstmt.setObject(i + 1, params[i]);
				}			
			}
			n = pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return n;
	}
	/**
	 * 执行查询所返回的Resultset对象
	 **/
	
	public static ResultSet executeQuery (String sql, Object[] params) {		
		conn = getConnection();
		try {
			pstmt = conn.prepareStatement(sql);
			if (params != null) {
				for (int i = 0; i < params.length; i++) {
					pstmt.setObject(i + 1, params[i]);
				}				
			}			
		    rs = pstmt.executeQuery();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return rs;
	}	
	
	/**
	 * 执行查询所返回的Resultset对象,参数为list
	 **/
	
	public static ResultSet exeQuery(String sql, List<Object> params) {		
		conn = getConnection();
		try {
			pstmt = conn.prepareStatement(sql);
			if (params != null) {
				for (int i = 0; i < params.size(); i++) {
					pstmt.setObject(i + 1, params.get(i));
				}				
			}			
		    rs = pstmt.executeQuery();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return rs;
	}	
	
	
	public static void close(Connection conn){
		if(conn != null){
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
	
	public static void close(Statement stmt){
		if(stmt != null){
			try {
				stmt.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
	
	public static void close(ResultSet rs){
		if(rs != null){
			 try {
				rs.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
	
	/**
	 * 关闭数据库资源
	 * @param rs
	 * @param stmt
	 * @param conn
	 */
	public static void closeAll() {
		try {
			if (rs != null) {
				rs.close();
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		try {
			if (pstmt != null) {
				pstmt.close();
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		try {
			if (conn != null) {
				conn.close();
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
}
