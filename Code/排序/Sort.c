#include "Sort.h"
#include "Stack.h"

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void PrintArray(int* nums, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",nums[i]);
	}
	printf("\n");
}

void InsertSort(int* nums, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = nums[end + 1];
		while (end >= 0)
		{
			if (temp < nums[end])
			{
				nums[end + 1] = nums[end];
			}
			else
			{
				break;
			}
          
			end--;
		}
		nums[end + 1] = temp;
	}
}

//ʱ�临�Ӷȣ�O(N^1.3)
void ShellSort(int* nums, int n)
{
	/*��gap > 1ʱ����Ԥ���򣬵�gap == 1ʱ��ʵ���򣨲�������,ʱ�临�Ӷ�ΪO(N)��*/
	int gap = n;
	while (gap > 1)
	{
		//gap /= 3 + 1,����д��
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = nums[end + gap];
			while (end >= 0)
			{
				if (temp < nums[end])
				{
					nums[end + gap] = nums[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			nums[end + gap] = temp;
		}
	}
}

void BubbleSort(int* nums, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		/*�������������Ԫ���Ѿ����������ֱ������ѭ��*/
		int exchange = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(&nums[j], &nums[j + 1]);
				exchange = 1;
			}
		}
		if(exchange == 0)
		{
			break;
		}
	}
}

void SelectSort(int* nums, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int max_index = begin, min_index = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (nums[i] > nums[max_index])
			{
				max_index = i;
			}
			if (nums[i] < nums[min_index])
			{
				min_index = i;
			}
		}

		swap(&nums[begin], &nums[min_index]);
		/*��ֹ����Ԫ�ظպþ�����СԪ�ص��±��е�������ʧ��*/
		if (max_index == begin)
		{
			max_index = min_index;
		}
		swap(&nums[end], &nums[max_index]);
		begin++;
		end--;
	}
}

int GetMiddle(int* nums, int left, int right)
{
	int middle = (right + left) / 2;
	if (nums[left] > nums[middle])
	{
		if (nums[left] > nums[right])//nums[left]���
		{
			if (nums[middle] > nums[right])
			{
				return right;
			}
			else
			{
				return middle;
			}
		}
		else//left��middle�󣬱�rightС
		{
			return left;
		}
	}
	else
	{
		if (nums[middle] > nums[right])//middle���
		{
			if (nums[left] > nums[right])
			{
				return right;
			}
			else
			{
				return left;
			}
		}
		else //middle��left�󣬱�rightС
		{
			return middle;
		}
	}
}

//ע��������
//һ����������Ԫ����ȵ�����ѭ��������취����nums[right] >= nums[key_i]��ע��Ҫ�ӵ��ںţ�
//����������Ԫ�ؾ���������Խ����ʣ�����취��ǰ�����left < right &&��
//�������keyֱ�Ӵ�ľ�������Ԫ�صĻ��������Ǿֲ��������½���ʧ�ܣ�����취��keyֵ���±������ָ�������Ԫ�أ�
//�����汾
int PartSort_1(int* nums, int left, int right)
{
	/*����ȡ��*/
	int middle = GetMiddle(nums, left, right);
	swap(&nums[left], &nums[middle]);
	/*ÿһ��ִ�и������ȷ��������key_i�±��Ԫ��*/
	int key_i = left;
	//int* key_i = nums[left];
	while (left < right)
	{
		/*�ȴ��ұ߿�ʼ��*/
		/*��С*/
		while (left < right && nums[right] >= nums[key_i])
		{
			--right;
		}

		/*�Ҵ�*/
		while (left < right && nums[left] <= nums[key_i])
		{
			++left;
		}
		swap(&nums[left], &nums[right]);
	}

	swap(&nums[key_i], &nums[left]);
	return left;
}

//�������򣨲��������ڿӷ���
//��һ��д��Ȼ�ͺ���д��һģһ�����úú�:)
int PartSort_2(int* nums, int left, int right)
{
	/*����ȡ��*/
	int middle = GetMiddle(nums, left, right);
	swap(&nums[left], &nums[middle]);
	int key = nums[left];
	/*int hole = left;*/
	while (left < right)
	{
		while (left < right && nums[right] >= key)
		{
			--right;
		}
		/*nums[hole] = nums[right];
		hole = right;*/
		nums[left] = nums[right];

		while (left < right && nums[left] <= key)
		{
			++left;
		}
		/*nums[hole] = nums[left];
		hole = left;*/
		nums[right] = nums[left];
	}
	nums[left] = key;
	/*nums[hole] = key;*/
	return left;
}

//�������򣨲�������ǰ��ָ�뷨��
int PartSort_3(int* nums, int left, int right)
{
	/*����ȡ��*/
	int middle = GetMiddle(nums, left, right);
	swap(&nums[left], &nums[middle]);

	int key_i = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		if (nums[cur] < nums[key_i] && ++prev != cur)
		{
			swap(&nums[prev], &nums[cur]);
		}

		/*if (nums[cur] < nums[key_i])
		{
			++prev;
			if (nums[prev] > nums[key_i])
			{
				swap(&nums[prev], &nums[cur]);
			}
		}*/
		++cur;
	}
	swap(&nums[prev], &nums[key_i]);
	return prev;
}

void QuickSort(int* nums, int begin, int end)
{
	
	if (begin >= end)
	{
		return;
 	}

	//С�����Ż��������ʱ�����Ѿ���С����ʱ���Ͳ��õݹ�������򣬶���ֱ��ʹ�ò������򣬽��͵ݹ�ʹ�ô���
	if (begin - end + 1 > 10)
	{
		int key_i = PartSort_3(nums, begin, end);
		QuickSort(nums, begin, key_i - 1);
		QuickSort(nums, key_i + 1, end);
	}
	else
	{
		InsertSort(nums + begin, end - begin + 1);
	}
}

void QuickSort_2(int* nums, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int middle = GetMiddle(nums, left, right);
	swap(&nums[middle], &nums[left]);
	int key = nums[left];
	int begin = left, end = right, cur = left + 1;
	while (cur <= right)
	{
		if (nums[cur] < key)
		{
			swap(&nums[cur], &nums[left]);
			++left;
			++cur;
		}
		else if(nums[cur] == key)
		{
			++cur;
		}
		else
		{
			swap(&nums[cur], &nums[right]);
			--right;
		}
	}

	//[begin, left - 1] [left, right] [right + 1, end]
	QuickSort_2(nums, begin, left - 1);
	QuickSort_2(nums, right + 1, end);
}

void QuickSortNonR(int* nums, int begin, int end)
{
	ST s;
	StackInit(&s);
	StackPush(&s, end);
	StackPush(&s, begin);
	while (!StackEmpty(&s))
	{
		int left = StackTop(&s);
		StackPop(&s);

		int right = StackTop(&s);
		StackPop(&s);

		int key_i = PartSort_1(nums, left, right);
		if (key_i + 1 < right)
		{
			StackPush(&s, right);
			StackPush(&s, key_i + 1);
		}

		if (key_i - 1 > left)
		{
			StackPush(&s, key_i - 1);
			StackPush(&s, left);
		}
	}
}

void _MergeSort(int* nums, int* temp, int begin, int end)
{
	if (end <= begin)
	{
		return;
	}

	int mid = (begin + end) / 2;
	/*�ݹ����*/
	//��������ע����ôд����Ȼ��������޵ݹ�
	/*_MergeSort(nums, temp, begin, mid - 1);
	_MergeSort(nums, temp, mid, end);*/
	_MergeSort(nums, temp, begin, mid);
	_MergeSort(nums, temp, mid + 1, end);

	/*�ݹ���ɿ�ʼ����*/
	int begin_1 = begin, end_1 = mid;
	int begin_2 = mid + 1, end_2 = end;
	/*����temp������±�*/
	int index = begin;
	while (begin_1 <= end_1 && begin_2 <= end_2)
	{
		if (nums[begin_1] < nums[begin_2])
		{
			temp[index++] = nums[begin_1++];
		}
		else
		{
			temp[index++] = nums[begin_2++];
		}
	}

	while (begin_1 <= end_1)
	{
		temp[index++] = nums[begin_1++];
	}
	while (begin_2 <= end_2)
	{
		temp[index++] = nums[begin_2++];
	}

	memcpy(nums + begin, temp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* nums, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}

	_MergeSort(nums, temp, 0, n - 1);
	free(temp);
}

void MergeSortNonR(int* nums, int n)
{
	int gap = 1;
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}

	while(gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin_1 = i, end_1 = i + gap - 1;
			int begin_2 = i + gap, end_2 = i + 2 * gap - 1;
			int index = i;

			//���end_1,begin_2����nҪ��Ļ���˵��������һ��������ȫû�б�Ҫ�鲢��ֱ�������һ��鲢����
			if (begin_2 >= n)
			{
				break;
			}
			//���ֻ��end_2��n��Ļ���˵�������������һ�ι鲢����ι鲢ֱ�ӽ����һ������һ��鲢����
			if (end_2 >= n)
			{
				end_2 = n - 1;
			}

			while (begin_1 <= end_1 && begin_2 <= end_2)
			{
				if (nums[begin_1] < nums[begin_2])
				{
					temp[index++] = nums[begin_1++];
				}
				else
				{
					temp[index++] = nums[begin_2++];
				}
			}

			while (begin_1 <= end_1)
			{
				temp[index++] = nums[begin_1++];
			}
			while (begin_2 <= end_2)
			{
				temp[index++] = nums[begin_2++];
			}
			memcpy(nums + i, temp + i, sizeof(int)*(end_2 - i + 1));
		}
		gap *= 2;
	}
	free(temp);
}

void CountSort(int* nums, int n)
{
	int min = nums[0], max = nums[0];
	for (int i = 0; i < n; i++)
	{
		if (nums[i] < min)
		{
			min = nums[i];
		}
		if (nums[i] > max)
		{
			max = nums[i];
		}
	}
    
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);

	for (int i = 0; i < n; i++)
	{
		count[nums[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			nums[j++] = i + min;
		}
	}
}