#include "filesys.h"

namespace filesys
{
	// 递归遍历文件夹
	void fileInFolder(const filesystem::path& path, int level = 0) {
		for (const filesystem::directory_entry& entry: filesystem::directory_iterator(path)) {
			auto filename = entry.path().filename().string();
			if (entry.is_directory()) {
				cout << setw(level * 4) << "- " << filename << endl;
				fileInFolder(entry, level + 1);
			} else if (entry.is_regular_file())
				cout << setw(level * 4) << "- " << filename << endl;
		}
	}

	void test01() {
		filesystem::path path{ "/tmp" };
		cout << "遍历文件夹下所有的文件：" << path.string() << endl;
		fileInFolder(path);
	}

	// 合并路径
	void test02() {
		filesystem::path path{ "/tmp" };
		path /= "net_affinity.log";
		cout << path.string() << " is exist " << filesystem::exists(path) << endl;

		cout << "文件名：" << path.filename().string()
			 << " 扩展名：" << path.extension().string() << endl;

		filesystem::path path1{ "/tmp/net_affinity.log" };
		cout << "文件大小：" << filesystem::file_size(path1)
			 << " 修改时间：" << filesystem::last_write_time(path1).time_since_epoch().count() << endl;
	}

	// 读文件
	void test03() {
		filesystem::path path{ "/tmp/net_affinity.log" };
		ifstream ifs{ path };
		stringstream strStream;
		strStream << ifs.rdbuf();
		cout << strStream.str() << endl;
		ifs.close();
	}

	void test04() {
		filesystem::path path{ "/tmp/net_affinity.log" };
		ifstream ifs(path, ios::in | ios::binary | ios::ate);
		ifstream::pos_type filesize = ifs.tellg();
		ifs.seekg(0, ios::beg);
		vector<char> bytes(filesize);
		ifs.read(bytes.data(), filesize);
		cout << string(bytes.data(), filesize) << endl;
		ifs.close();
	}

	void main() {
//		test01();
//		test02();
//		test03();
//		test04();

	}
}
