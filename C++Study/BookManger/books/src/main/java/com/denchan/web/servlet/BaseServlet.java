package com.denchan.web.servlet;

import java.io.IOException;
import java.lang.reflect.Method;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * 
 * @author denchan
 * 所有的servlet都要继承此类
 */
public class BaseServlet extends HttpServlet {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
	protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		try {
			//设置编码
			req.setCharacterEncoding("UTF-8");
			resp.setCharacterEncoding("UTF-8");
			resp.setContentType("text/html;charser=utf-8");
			//获取方法名
			String m = req.getParameter("method");
			//获取类
			Class<? extends BaseServlet> clazz = this.getClass();
			Method method = clazz.getDeclaredMethod(m, HttpServletRequest.class,HttpServletResponse.class);
			method.setAccessible(true);
			method.invoke(this, req, resp);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("baseServlet异常处理");
		}
	}
	
	

}
