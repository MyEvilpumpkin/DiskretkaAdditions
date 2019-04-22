#include "CppUnitTest.h"
#include "../DiskretkaAdditions/P.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiskretkaAdditionsUnitTests {
	TEST_CLASS(NTests) {
	public:
		TEST_METHOD(COM_NN_D_Test) {
			Assert::IsTrue(COM_NN_D(N("0"), N("5")) == 1, L"Test 1");
		}
	};
}
