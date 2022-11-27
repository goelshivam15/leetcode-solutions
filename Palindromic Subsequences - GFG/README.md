# Palindromic Subsequences
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">Given a Binary String S (the string that contains only&nbsp;0's and 1's). Find the minimum number of palindromic subsequences that are needed&nbsp;to be removed such that string&nbsp;S becomes empty.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 5, S = "10001"
<strong>Output:</strong> 1
<strong>Explanation</strong>: We can remove whole S, as
S is already a palindrome.</span></pre>

<p><span style="font-size:18px">â€‹<strong>Example 2:&nbsp;</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 8, S = "10001001"
<strong>Output:</strong> 2
<strong>Explanation</strong>: First we'll remove sub-
sequence&nbsp;"111" and then "00000".</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>MinRemove()</strong>&nbsp;which takes the length of string and the string<strong>&nbsp;</strong>as inputs and returns the answer.<br>
<br>
<strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ N&nbsp;≤ 10<sup>8</sup></span></p>
</div>