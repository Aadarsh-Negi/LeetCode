# Count Inversions
##  Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given an array of integers. Find the Inversion Count in the array.&nbsp;</span></p>

<p><span style="font-size:18px"><em><strong>Inversion Count</strong>: </em>For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then&nbsp;the inversion count is the maximum.&nbsp;<br>
Formally, two elements a[i] and a[j] form an inversion if a[i] &gt; a[j] and i &lt; j.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 5, arr[] = {2, 4, 1, 3, 5}
<strong>Output</strong>: 3
<strong>Explanation</strong>: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 5
arr[] = {2, 3, 4, 5, 6}
<strong>Output</strong>: 0
<strong>Explanation</strong>: As the sequence is already 
sorted so there is no inversion count.</span></pre>

<p><span style="font-size:18px"><strong>Example 3:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 3, arr[] = {10, 10, 10}
<strong>Output</strong>: 0
<strong>Explanation</strong>: As all the elements of array 
are same, so there is no inversion count.</span></pre>

<p><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>inversionCount()</strong>&nbsp;which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.</span><br>
<br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(NLogN).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span><br>
<br>
<span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 ≤ N ≤ 5*10<sup>5</sup><br>
1 ≤ arr[i]&nbsp;≤ 10<sup>18</sup></span></p>
 <p></p>
            </div>