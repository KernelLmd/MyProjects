#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main() {
	char str[101];
	while (scanf("%s", str) != EOF) {
		string strobj(str);
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			char buf[103];
			scanf("%s", buf);

			int flag = buf[0] - '0';
			int begin = buf[1] - '0';
			int len = buf[2] - '0';
			int end = begin + len - 1;

			switch (flag)
			{
			case 0: {
				for (int j = begin; j < end; 
					 j++, end--) {
					char tmp = strobj[j];
					strobj[j] = strobj[end];
					strobj[end] = tmp;
				}
				cout << strobj << endl;
				break;
			}
			case 1: {
				string sub;
				sub.assign(buf, 3, string::npos);
				/*basic_string& assign( const basic_string& str,
				size_type pos,size_type count );
				�� str ���Ӵ� [pos, pos+count) �滻���ݡ�
				��������Ӵ�Խ�� string β������ count == npos ��
				��������Ӵ��� [pos, str.size()�����ǵ��ַ��������) ��*/
				strobj.replace(begin, len, sub);
				/*basic_string& replace( size_type pos, size_type count,
				const basic_string& str );*/
				cout << strobj << endl;
				break;
			}
			}
		}
	}
	return 0;
}