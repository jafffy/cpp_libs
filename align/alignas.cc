struct alignas(16) sse_t
{
  float sse_data[4];
};

alignas(128) char cacheline[128];

int main()
{}

