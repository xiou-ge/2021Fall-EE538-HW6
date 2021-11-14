
# HW6 EE538 - Computing Principles for Electrical Engineers

- Please clone the repository, edit [README.md](README.md) to answer questions, and fill up functions to finish the hw.
- For non-coding questions, you will find **Answer** below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests).
- For submission, please push your answers to Github before the deadline.
- Deadline: Monday, November 29th, at 11:59 PM (PDT)
- Total: 120 points. 100 points is considered full credit.
- **No late acceptance will be accepted for this assignment since the solutions will be provided right after the deadline.**

## Question 1 (10 Points. Easy)

Suppose we have the following map from a digit (represented as a character) to a set of characters:  

```
std::map<char, std::set<char>> m = {
   {'0', {'a', 'b'}},
   {'1', {'d', 'f'}},
   {'2', {'g', 'h'}},
   {'3', {'j', 'k'}},
   {'4', {'m', 'n'}},
   {'5', {'p', 'q'}},
   {'6', {'t', 'u'}},
   {'7', {'w', 'x'}},
   {'8', {'!', '?'}},
   {'9', {'*', '#'}},
 };
```

1. Return a vector of all possible strings that a given string of digits in can represent.
2. What is the worst case runtime and why?

**Example1:**
in: "34"
out: { "jm", "jn", "km", "kn" }


**Example2:**
in: "345"
out: { "jmp", "jmq", "jnp", "jnq", "kmp", "kmq", "knp", "knq" }

**Answer:**

## Question 2 (10 Points. Easy)

In this question we add one more constraint to the TSP problem (Traveling salesperson): We assign a gas value to each city. For each two cities i, j, you can only move from i to j if:

```
cur_gas >= weights[cur_node][i]
```

Where cur_gas is your current gas at city i. Once you enter a new city j, your cur_gas will be incremented by gas[j].

Example input:

```
weights = {
       {0, 40, 20, 35},
       {40, 0, 30, 10},
       {20, 30, 0, 30},
       {35, 10, 30, 0},
   };
   gas = {1000, 1000, 1000, 1000};
```

Output: 95. Explanation: We never run out of gas, so the min path cycle is 0, 2, 1, 3, with min_cost = 95.

```
weights = {
       {0, 40, 20, 35},
       {40, 0, 30, 10},
       {20, 30, 0, 30},
       {35, 10, 30, 0},
   };
 gas = {1, 1, 1, 1};
```

Output: INT_MAX (infinity): We won’t have enough gas to move from the start point.

The signature of the functions that you are implementing are give to you:

```
static int TSPWithGas(std::vector<std::vector<int>> &weights,
                       std::vector<int> &gas, int start);
static void TSPWithGas_aux(std::vector<std::vector<int>> &weights,
                            std::vector<int> &gas, int start, int cur_node,
                            std::vector<int> &cur_path, int cur_cost,
                            int cur_gas, int &min_cost,
                            std::vector<int> &min_path);
```

1. Why is start an input parameter of TSPWithGas? Couldn’t we write the function without start as a parameter?
2. For all the given parameters of TSPWithGas_aux, please explain why each of them is passed by a reference or by value. What is the justification for each choice?
3. Implement the body of each function.
4. Write some unit tests.

**Answer:**

**Make sure you pass the following tests.**

```
TEST(TSPWithGasTest, TSP) {
 std::vector<std::vector<int>> weights;
 std::vector<int> gas;
 
 {
   weights = {
       {0, 40, 20, 35},
       {40, 0, 30, 10},
       {20, 30, 0, 30},
       {35, 10, 30, 0},
   };
   // { 0, 2, 1, 3 }
   gas = {1000, 1000, 1000, 1000};
   EXPECT_EQ(95, TSPWithGas(weights, gas, 0));
 
   gas = {1, 1, 1, 1};
   EXPECT_EQ(INT_MAX, TSPWithGas(weights, gas, 0));
 
   gas = {95, 0, 0, 0};
   EXPECT_EQ(95, TSPWithGas(weights, gas, 0));
 
   gas = {20, 10, 30, 35};
   EXPECT_EQ(95, TSPWithGas(weights, gas, 0));
 }
 
 {
   weights = {
       {0, 40, 20, 35},
       {40, 0, 30, 100},
       {20, 30, 0, 30},
       {35, 100, 30, 0},
   };
 
   // { 0, 1, 2, 3 }
   gas = {135, 0, 0, 0};
   EXPECT_EQ(135, TSPWithGas(weights, gas, 0));
 
   gas = {40, 100, 0, 0};
   EXPECT_EQ(135, TSPWithGas(weights, gas, 0));
   gas = {40, 39};
   EXPECT_EQ(INT_MAX, TSPWithGas(weights, gas, 0));
 }
 
 {
   weights = {
       {0, 20, 42, 35},
       {20, 0, 30, 34},
       {42, 30, 0, 12},
       {35, 34, 12, 0},
 
   };
   gas = {1000, 1000, 1000, 1000};
   EXPECT_EQ(97, TSPWithGas(weights, gas, 0));
 
   gas = {97, 0, 0, 0};
   EXPECT_EQ(97, TSPWithGas(weights, gas, 0));
 
   gas = {42, 42, 13, 0};
   EXPECT_EQ(97, TSPWithGas(weights, gas, 0));
 }
 
 {
   weights = {
       {0, 10, 15, 20},
       {10, 0, 35, 25},
       {15, 35, 0, 30},
       {20, 25, 30, 0},
 
   };
   gas = {1000, 1000, 1000, 1000};
      EXPECT_EQ(80, TSPWithGas(weights, gas, 0));
 
   gas = {79, 1, 0, 0};
   EXPECT_EQ(80, TSPWithGas(weights, gas, 0));
 
   gas = {78, 1, 0, 1};
   EXPECT_EQ(80, TSPWithGas(weights, gas, 0));
 
   gas = {76, 1, 1, 2};
   EXPECT_EQ(80, TSPWithGas(weights, gas, 0));
 }
 
 {
   weights = {
       {0, 10, 15},
       {10, 0, 9},
       {15, 9, 0},
 
   };
   gas = {10, 9, 15};
   EXPECT_EQ(34, TSPWithGas(weights, gas, 0));
 
   gas = {9, 10, 15};
   EXPECT_EQ(INT_MAX, TSPWithGas(weights, gas, 0));
 }
}

```
