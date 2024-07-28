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

//时间复杂度：O(N^1.3)
void ShellSort(int* nums, int n)
{
	/*当gap > 1时都是预排序，当gap == 1时是实排序（插入排序,时间复杂度为O(N)）*/
	int gap = n;
	while (gap > 1)
	{
		//gap /= 3 + 1,两种写法
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
		/*如果这个数组里的元素已经是有序的则直接跳出循环*/
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
		/*防止最大的元素刚好就在最小元素的下标中导致排序失败*/
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
		if (nums[left] > nums[right])//nums[left]最大
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
		else//left比middle大，比right小
		{
			return left;
		}
	}
	else
	{
		if (nums[middle] > nums[right])//middle最大
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
		else //middle比left大，比right小
		{
			return middle;
		}
	}
}

//注意三个坑
//一、左右两个元素相等导致死循环（解决办法：例nums[right] >= nums[key_i]，注意要加等于号）
//二、该数组元素就是有序导致越界访问（解决办法：前面加上left < right &&）
//三、如果key直接存的就是数组元素的话，由于是局部变量导致交换失败（解决办法：key值存下标或者用指针存数组元素）
//霍尔版本
int PartSort_1(int* nums, int left, int right)
{
	/*三数取中*/
	int middle = GetMiddle(nums, left, right);
	swap(&nums[left], &nums[middle]);
	/*每一次执行该排序就确定了数组key_i下标的元素*/
	int key_i = left;
	//int* key_i = nums[left];
	while (left < right)
	{
		/*先从右边开始找*/
		/*找小*/
		while (left < right && nums[right] >= nums[key_i])
		{
			--right;
		}

		/*找大*/
		while (left < right && nums[left] <= nums[key_i])
		{
			++left;
		}
		swap(&nums[left], &nums[right]);
	}

	swap(&nums[key_i], &nums[left]);
	return left;
}

//快速排序（部分排序，挖坑法）
//第一次写竟然和杭哥写的一模一样，好好好:)
int PartSort_2(int* nums, int left, int right)
{
	/*三数取中*/
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

//快速排序（部分排序，前后指针法）
int PartSort_3(int* nums, int left, int right)
{
	/*三数取中*/
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

	//小区间优化：如果此时排序已经到小区间时，就不用递归继续排序，而是直接使用插入排序，降低递归使用次数
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
	/*递归过程*/
	//不可以是注释这么写，不然会进入无限递归
	/*_MergeSort(nums, temp, begin, mid - 1);
	_MergeSort(nums, temp, mid, end);*/
	_MergeSort(nums, temp, begin, mid);
	_MergeSort(nums, temp, mid + 1, end);

	/*递归完成开始排序*/
	int begin_1 = begin, end_1 = mid;
	int begin_2 = mid + 1, end_2 = end;
	/*访问temp数组的下标*/
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

			//如果end_1,begin_2都比n要大的话，说明最后的那一组数据完全没有必要归并，直接在最后一起归并即可
			if (begin_2 >= n)
			{
				break;
			}
			//如果只是end_2比n大的话，说明即将进行最后一次归并，这次归并直接将最后一组数据一起归并即可
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