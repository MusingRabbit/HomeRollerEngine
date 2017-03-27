
#include <stdlib.h>
#include "gtest\gtest.h"
#include "DataStructures\Stack.h"
using namespace Engine;

struct TestStruct
{
	int intData = 0;
	std::string stringData = "";
};

TEST(Stack, Valid_Constructor) {
	Stack<int> testStack(1000);
	EXPECT_EQ(testStack.GetSize(), 1000);
	EXPECT_EQ(testStack.Top(), 0);
}

TEST(Stack, InValid_Constructor) {
	EXPECT_THROW({ Stack<int> testStack(0); }, std::exception);
	EXPECT_THROW({ Stack<int> testStack(-1); }, std::exception);
}


TEST(Stack, Valid_Push) {
	int iFixedSize = 1000;

	Stack<int> testStack1(iFixedSize);
	Stack<TestStruct> testStack2(iFixedSize);

	for (int i = 0; i < iFixedSize; i++) {
		int value = std::rand();
		EXPECT_EQ(testStack1.Top(), i);
		testStack1.Push(value);
	}

	for (int i = 0; i < iFixedSize; i++) {
		EXPECT_EQ(testStack2.Top(), i);
		
		TestStruct newData;
		newData.intData = std::rand();
		newData.stringData = "testString";

		testStack2.Push(newData);
	}

}

TEST(Stack, Invalid_Push) {
	int iStackSize = 1000;
	Stack<int> testStack1(iStackSize);

	for (int i = 0; i < iStackSize; i++) {
		testStack1.Push(std::rand());
	}

	EXPECT_THROW({ testStack1.Push(std::rand()); }, std::exception);
}

TEST(Stack, Pop) {
	int iStackSize = 1000;
	int values [1000];

	Stack<int> testStack1(iStackSize);

	for (int i = 0; i < iStackSize; i++) {
		int value = std::rand();
		values[i] = value;
		testStack1.Push(value);
	}

	for (int i = 0; i < iStackSize; i++) {
		int result = testStack1.Pop();
		int idx = (iStackSize - (i + 1));
		EXPECT_EQ(result, values[idx]);
	}

}
