#include <iostream>
#include <string.h>
using namespace std;

char mirror(char c)	//�����ַ��;�����ӳ�亯��
{
	//���ַ��;�����ȵ��ַ���������same
	char same[15] = { 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'X', 'Y', '0', '1', '8'};
	//�ж�c�Ƿ���same��
	for (int i = 0; i < strlen(same); i++)
	{
		if (c == same[i])
			return same[i];
	}
	//���ַ��;����໥�ԳƵ��ַ���������group
	char group[4][3] = { "3E", "JL", "2S", "5Z" };
	//�ж�c�Ƿ���group��
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 2; k++)
		{
			if (c == group[j][k])
				return group[j][!k];	//!k��Ϊ��j���ַ��жԳƵ��ַ�
		}
	return '\0';
}

string longestMirrorString(string strs)
{
	int len = strs.length();	//���г���len
	string ans, odd;
	int left, right;
	for (int mid = 1; mid < len; mid++)
	{
		left = mid - 1;		//��ʼ��left right
		right = mid + 1;
		while (left >= 0 && right <= strs.length()-1 && strs[right] != '\0' && strs[right] == mirror(strs[left]))
		{
			//�ڲ�Խ���ǰ�����ж�strs[right] != '\0' && strs[right] == mirror(strs[left])�Ƿ����
			//cout << "mirror equal: " << strs[left] << ", " << strs[right] << endl;
			left--;
			right++;
		}
		odd = strs.substr(left+1, right-left-1);	//ͨ����õ�left��right�õ�strs��Ӧλ�õ��ִ�odd
		if (odd.length() > 2)	//��odd�ĳ��ȴ���2ʱ����С������������г���Ϊ3��
		{
			//cout << "ans append : " << odd << endl;
			ans.append(odd);	//��odd��ֵ��ansĩβ
			ans = ans + ' ';	//ͨ��' '�ָ��ҵ������������������ִ�
		}
	}
	return ans;
}

int main()
{
	//  ����mirror
	//	char c;
	//	cin >> c;
	//	cout << mirror(c);

	//  ���Ժ���longestMirrorString
	string a;
	cout << "input a string: ";
	cin >> a;
	cout << "longestMirrorString is " << longestMirrorString(a) << endl;
	return 0;
}
