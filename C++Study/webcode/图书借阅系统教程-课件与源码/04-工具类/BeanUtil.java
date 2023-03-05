package com.sxt.utils;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Map;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.beanutils.ConversionException;
import org.apache.commons.beanutils.ConvertUtils;
import org.apache.commons.beanutils.Converter;
/**
 * 
 * @author sxt
 *
 */
public class BeanUtil {

	static {
		// 注册 自动转换bean
		ConvertUtils.register(new DateConverter("yyyy-mm-dd"), Date.class);
	}

	// getBean 主要是从map 映射为 javabean对象。 场景为： request当中映射为javabean
	@SuppressWarnings("unchecked")
	public static <T> T getBean(Map<String, String[]> map, Class<T> clazz) {
		Object bean = null;
		try {
			bean = clazz.newInstance();
			BeanUtils.populate(bean, map);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return (T) bean;
	}
}

class DateConverter implements Converter {

	private static SimpleDateFormat format;

	public DateConverter(String pattern) {
		format = new SimpleDateFormat(pattern);
	}

	@Override
	public Object convert(@SuppressWarnings("rawtypes") Class type, Object value) {
		if (value == null) {
            return null;
        }

        if (value instanceof String) {
            String tmp = (String) value;
            
            if (tmp.trim().length() == 0) {
                return null;
            } else {
                try {
                    return format.parse(tmp);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } else {
            throw new ConversionException("not String");
        }
        return value;
	}
}