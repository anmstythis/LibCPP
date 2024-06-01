extern "C" __declspec(dllexport) float Sum(float a, float b)
{
	return a + b;
}

extern "C" __declspec(dllexport) float Neg(float a, float b)
{
	return a - b;
}

extern "C" __declspec(dllexport) float Mult(float a, float b)
{
	return a * b;
}

extern "C" __declspec(dllexport) float Div(float a, float b)
{
	return a / b;
}