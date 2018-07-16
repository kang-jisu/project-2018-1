

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.apache.ibatis.session.SqlSession;

public class UserDaoImpl implements UserDao {

	public void selectAll(PageUtil<User> page) {
		SqlSession session = MySqlSession.getSession();
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("num1", page.getIndex() * page.getSize());
		map.put("num2", (page.getIndex() - 1) * page.getSize());
		List<User> list = session.selectList("UserInfo.all", map);
		page.setCount((Integer) session.selectOne("UserInfo.count"));
		page.setList(list);
		MySqlSession.closeSession();
	}

	public int del(int id) {
	
		return 1;
	}

	public User ById(int id) {
	
		return new User();
	}

	public int upd(User u) {
	
		return 1;
	}

	public int add(User u) {
		
		return 1;
	}
}
