<div class="challenge-content lesson-algorithm-main-section " data-challengeable-id="1412" data-challengeable-type="algorithm" data-algorithm-type="standard" data-language="cpp" data-user-id="624683" data-interface-type="function" data-lesson-comment-activation-score="30" data-is-lesson="true">
    <div></div>
    

<div class="main-section ">
  <div class="guide-section " id="tour2" style="width: calc(40% - 12px);">
    <div class="guide-section-description">
      <h6 class="guide-section-title">문제 설명</h6>
      <div class="markdown solarized-dark"><p>xx 회사의 2xN명의 사원들은 N명씩 두 팀으로 나눠 숫자 게임을 하려고 합니다. 두 개의 팀을 각각 A팀과 B팀이라고 하겠습니다. 숫자 게임의 규칙은 다음과 같습니다.</p>

<ul>
<li>먼저 모든 사원이 무작위로 자연수를 하나씩 부여받습니다.</li>
<li>각 사원은 딱 한 번씩 경기를 합니다.</li>
<li>각 경기당 A팀에서 한 사원이, B팀에서 한 사원이 나와 서로의 수를 공개합니다. 그때 숫자가 큰 쪽이 승리하게 되고, 승리한 사원이 속한 팀은 승점을 1점 얻게 됩니다.</li>
<li>만약 숫자가 같다면 누구도 승점을 얻지 않습니다.</li>
</ul>

<p>전체 사원들은 우선 무작위로 자연수를 하나씩 부여받았습니다. 그다음 A팀은 빠르게 출전순서를 정했고 자신들의 출전 순서를 B팀에게 공개해버렸습니다. B팀은 그것을 보고 자신들의 최종 승점을 가장 높이는 방법으로 팀원들의 출전 순서를 정했습니다. 이때의 B팀이 얻는 승점을 구해주세요.<br>
A 팀원들이 부여받은 수가 출전 순서대로 나열되어있는 배열 <code>A</code>와 i번째 원소가 B팀의 i번 팀원이 부여받은 수를 의미하는 배열 <code>B</code>가 주어질 때, B 팀원들이 얻을 수 있는 최대 승점을 return 하도록 solution 함수를 완성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li><code>A</code>와 <code>B</code>의 길이는 같습니다.</li>
<li><code>A</code>와 <code>B</code>의 길이는 <code>1</code> 이상 <code>100,000</code> 이하입니다.</li>
<li><code>A</code>와 <code>B</code>의 각 원소는 <code>1</code> 이상 <code>1,000,000,000</code> 이하의 자연수입니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>A</th>
<th>B</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[5,1,3,7]</td>
<td>[2,2,6,8]</td>
<td>3</td>
</tr>
<tr>
<td>[2,2,2,2]</td>
<td>[1,1,1,1]</td>
<td>0</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1<br>
<img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0de59edf-76e1-4313-984a-4b2bd40911fb/number_game2_yt913p.png" title="" alt="number_game2_yt913p.png"><br>
A 팀은 숫자 5를 부여받은 팀원이 첫번째로 출전하고, 이어서 1,3,7을 부여받은 팀원들이 차례대로 출전합니다.<br>
B 팀원들을 4번, 2번, 3번, 1번의 순서대로 출전시킬 경우 팀원들이 부여받은 숫자들은 차례대로 8,2,6,2가 됩니다. 그러면, 첫 번째, 두 번째, 세 번째 경기에서 승리하여 3점을 얻게 되고, 이때가 최대의 승점입니다.</p>

<p>입출력 예 #2<br>
B 팀원들을 어떤 순서로 출전시켜도 B팀의 승점은 0점입니다.</p>
</div>
    </div>
  </div>


  <div class="gutter gutter-horizontal" style="width: 24px; background-image: url(&quot;/assets/img-grippie-vertical-cd0206a7a3122deb89a192c09ca241e8614c02e38b4f47ffb3af1a2e5246b85f.png&quot;);"></div><div class="run-section" style="width: calc(60% - 12px);">
    <div id="tour3" class="code-section" onkeyup="Hera.tryoutChallenges.resizeEditor(this);" style="height: calc(60% - 7px);">
      <div class="editor">
        <ul class="nav nav-pills editor-nav-pills tap-form">
    <input type="hidden" name="initial_code_4159" id="initial_code_4159" value="#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    return answer;
}" autocomplete="off">
    <input id="4159" data-type="code" data-language="cpp" type="hidden" value="#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0; i < A.size(); ++i) {
        if(B[i] - A[i] > 0)
            ++answer;
    }
    return answer;
}">
    <li class="nav-item">
      <a href="#" class="btn-tab nav-link active" data-id="4159" data-language="cpp">
        solution.cpp </a>
    </li>
</ul>
        
          <textarea hidden="" id="code" name="code" style="display: none;">#include &lt;bits/stdc++.h&gt;

using namespace std;

int solution(vector&lt;int&gt; A, vector&lt;int&gt; B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0; i &lt; A.size(); ++i) {
        if(B[i] - A[i] &gt; 0)
            ++answer;
    }
    return answer;
}</textarea><div class="CodeMirror cm-s-tomorrow-night-bright CodeMirror-wrap" translate="no"><div style="overflow: hidden; position: relative; width: 3px; height: 0px; top: 400.794px; left: 67.6328px;"><textarea autocorrect="off" autocapitalize="off" spellcheck="false" tabindex="0" style="position: absolute; bottom: -1em; padding: 0px; width: 1000px; height: 1em; min-height: 1em; outline: none;"></textarea></div><div class="CodeMirror-vscrollbar" tabindex="-1" cm-not-content="true" style="bottom: 0px;"><div style="min-width: 1px; height: 0px;"></div></div><div class="CodeMirror-hscrollbar" tabindex="-1" cm-not-content="true"><div style="height: 100%; min-height: 1px; width: 0px;"></div></div><div class="CodeMirror-scrollbar-filler" cm-not-content="true"></div><div class="CodeMirror-gutter-filler" cm-not-content="true"></div><div class="CodeMirror-scroll" tabindex="-1" draggable="false"><div class="CodeMirror-sizer" style="margin-left: 48px; margin-bottom: -8px; border-right-width: 42px; min-height: 411px; padding-right: 0px; padding-bottom: 0px;"><div style="position: relative; top: 0px;"><div class="CodeMirror-lines" role="presentation"><div role="presentation" style="position: relative; outline: none;"><div class="CodeMirror-measure"></div><div class="CodeMirror-measure"></div><div style="position: relative; z-index: 1;"></div><div class="CodeMirror-cursors" style=""><div class="CodeMirror-cursor" style="left: 19.6328px; top: 380.794px; height: 22.3984px;">&nbsp;</div></div><div class="CodeMirror-code" role="presentation" style=""><div style="position: relative;" class=""><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">1</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"><span class="cm-meta">#include &lt;bits/stdc++.h&gt;</span></span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">2</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"><span cm-text="">&ZeroWidthSpace;</span></span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">3</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"><span class="cm-keyword">using</span> <span class="cm-keyword">namespace</span> <span class="cm-def">std</span>;</span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">4</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"><span cm-text="">&ZeroWidthSpace;</span></span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">5</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"><span class="cm-type">int</span> <span class="cm-def">solution</span>(<span class="cm-variable">vector</span><span class="cm-operator">&lt;</span><span class="cm-type">int</span><span class="cm-operator">&gt;</span> <span class="cm-variable">A</span>, <span class="cm-variable">vector</span><span class="cm-operator">&lt;</span><span class="cm-type">int</span><span class="cm-operator">&gt;</span> <span class="cm-variable">B</span>) {</span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">6</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp;<span class="cm-type">int</span> <span class="cm-variable">answer</span> <span class="cm-operator">=</span> <span class="cm-number">0</span>;</span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">7</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp;<span class="cm-variable">sort</span>(<span class="cm-variable">A</span>.<span class="cm-variable">begin</span>(),<span class="cm-variable">A</span>.<span class="cm-variable">end</span>());</span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">8</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp;<span class="cm-variable">sort</span>(<span class="cm-variable">B</span>.<span class="cm-variable">begin</span>(),<span class="cm-variable">B</span>.<span class="cm-variable">end</span>());</span></pre></div><div style="position: relative;" class=""><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">9</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp;<span class="cm-keyword">for</span>(<span class="cm-type">int</span> <span class="cm-variable">i</span> <span class="cm-operator">=</span> <span class="cm-number">0</span>, <span class="cm-variable">j</span> <span class="cm-operator">=</span> <span class="cm-number">0</span>; <span class="cm-variable">i</span> <span class="cm-operator">&lt;</span> <span class="cm-variable">B</span>.<span class="cm-variable">size</span>(); <span class="cm-operator">++</span><span class="cm-variable">i</span>) {</span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">10</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp; &nbsp; &nbsp;<span class="cm-keyword">if</span>(<span class="cm-variable">A</span>[<span class="cm-variable">j</span>] <span class="cm-operator">-</span> <span class="cm-variable">B</span>[<span class="cm-variable">i</span>] <span class="cm-operator">&lt;</span> <span class="cm-number">0</span>) {</span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">11</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<span class="cm-operator">++</span><span class="cm-variable">answer</span>;</span></pre></div><div class="" style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">12</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<span class="cm-operator">++</span><span class="cm-variable">j</span>;</span></pre></div><div style="position: relative;"><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">13</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp; &nbsp;  }</span></pre></div><div style="position: relative;" class=""><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">14</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp;  }</span></pre></div><div style="position: relative;" class=""><div class="CodeMirror-gutter-wrapper" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">15</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;"> &nbsp; &nbsp;<span class="cm-keyword">return</span> <span class="cm-variable">answer</span>;</span></pre></div><div style="position: relative;" class="CodeMirror-activeline"><div class="CodeMirror-activeline-background CodeMirror-linebackground"></div><div class="CodeMirror-gutter-background CodeMirror-activeline-gutter" style="left: -48px; width: 48px;"></div><div class="CodeMirror-gutter-wrapper CodeMirror-activeline-gutter" aria-hidden="true" style="left: -48px;"><div class="CodeMirror-linenumber CodeMirror-gutter-elt" style="left: 0px; width: 21px;">16</div></div><pre class=" CodeMirror-line " role="presentation"><span role="presentation" style="padding-right: 0.1px;">}</span></pre></div></div></div></div></div></div><div style="position: absolute; height: 42px; width: 1px; border-bottom: 0px solid transparent; top: 411px;"></div><div class="CodeMirror-gutters" style="height: 453px; left: 0px;"><div class="CodeMirror-gutter CodeMirror-linenumbers" style="width: 48px;"></div></div></div></div>
      </div>
    </div>

    <div class="gutter gutter-vertical" style="height: 14px; background-image: url(&quot;/assets/img-grippie-horizon-2029be95ca34dfe8c756d091c6f53a6a007e3a66c7c68863ce6f54fe23d4f371.png&quot;);"></div><div class="output-section" id="tour6" style="height: 0px;" data-is-mobile="true">
      <div class="tab-header">
          <div id="output-title" class="output-title output-only active success" data-toggle="tab">
            <span class="connection-status connected" data-container="body" data-toggle="popover" data-placement="top" title="" data-html="true" data-content="
                    <h6>네트워크가 불안정하여 서버와의 연결이 끊어졌습니다.
                    페이지 새로고침을 하거나 네트워크가 안정적이 되면 자동으로 재 연결됩니다.</h6>
                    <h6 style='margin-top: 4px;'>네트워크가 정상임에도 계속해서 연결이 끊어진 상태가 지속된다면 네트워크 방화벽 문제일 수 있습니다.
                    모바일 테더링 등 다른 네트워크를 통해 테스트에 접속해 보세요.</h6>" data-original-title="서버와의 연결 끊김">
              <svg class="ic-24"><use xlink:href="/assets/svg-defs-bfd029363f2c8bdfe15e5ec48b70c852adde08037cfa9a9ab8024207254aaa7d.svg#ic-power-off"></use></svg>
            </span>

            실행 결과
              <a id="stop-button" class="btn btn-sm btn-danger" href="#" style="display: none;">실행 중지</a>
            <span id="output-spinner" class="spinner hidden">
              <span class="bounce1"></span>
              <span class="bounce2"></span>
              <span class="bounce3"></span>
            </span>
          </div>
      </div>

      <div class="console tab-content">
          <div id="output" class="console-output tab-pane fade in active show banner">
            <div id="output-wrapper"><pre class="console-content"><div></div><div class="console-heading">채점을 시작합니다.</div><div class="console-message">정확성  테스트</div><table class="console-test-group" data-category="correctness"><tbody><tr data-testcase-id="22278"><td valign="top" class="td-label">테스트 1 <span>〉</span></td><td class="result passed">통과 (0.01ms, 4.12MB)</td></tr><tr data-testcase-id="22279"><td valign="top" class="td-label">테스트 2 <span>〉</span></td><td class="result passed">통과 (0.01ms, 4.02MB)</td></tr><tr data-testcase-id="22280"><td valign="top" class="td-label">테스트 3 <span>〉</span></td><td class="result passed">통과 (0.01ms, 4.14MB)</td></tr><tr data-testcase-id="22281"><td valign="top" class="td-label">테스트 4 <span>〉</span></td><td class="result passed">통과 (0.01ms, 3.63MB)</td></tr><tr data-testcase-id="22282"><td valign="top" class="td-label">테스트 5 <span>〉</span></td><td class="result passed">통과 (0.01ms, 3.68MB)</td></tr><tr data-testcase-id="22283"><td valign="top" class="td-label">테스트 6 <span>〉</span></td><td class="result passed">통과 (0.02ms, 4.12MB)</td></tr><tr data-testcase-id="22284"><td valign="top" class="td-label">테스트 7 <span>〉</span></td><td class="result passed">통과 (0.01ms, 4.14MB)</td></tr><tr data-testcase-id="22285"><td valign="top" class="td-label">테스트 8 <span>〉</span></td><td class="result passed">통과 (0.01ms, 4.13MB)</td></tr><tr data-testcase-id="22286"><td valign="top" class="td-label">테스트 9 <span>〉</span></td><td class="result passed">통과 (0.07ms, 4.12MB)</td></tr><tr data-testcase-id="22287"><td valign="top" class="td-label">테스트 10 <span>〉</span></td><td class="result passed">통과 (0.06ms, 3.69MB)</td></tr><tr data-testcase-id="22288"><td valign="top" class="td-label">테스트 11 <span>〉</span></td><td class="result passed">통과 (0.08ms, 3.69MB)</td></tr><tr data-testcase-id="22289"><td valign="top" class="td-label">테스트 12 <span>〉</span></td><td class="result passed">통과 (0.05ms, 3.68MB)</td></tr><tr data-testcase-id="22290"><td valign="top" class="td-label">테스트 13 <span>〉</span></td><td class="result passed">통과 (0.57ms, 4.23MB)</td></tr><tr data-testcase-id="22291"><td valign="top" class="td-label">테스트 14 <span>〉</span></td><td class="result passed">통과 (1.09ms, 4.19MB)</td></tr><tr data-testcase-id="22292"><td valign="top" class="td-label">테스트 15 <span>〉</span></td><td class="result passed">통과 (0.60ms, 4.21MB)</td></tr><tr data-testcase-id="22293"><td valign="top" class="td-label">테스트 16 <span>〉</span></td><td class="result passed">통과 (0.98ms, 4.13MB)</td></tr><tr data-testcase-id="22294"><td valign="top" class="td-label">테스트 17 <span>〉</span></td><td class="result passed">통과 (0.05ms, 4.21MB)</td></tr><tr data-testcase-id="22295"><td valign="top" class="td-label">테스트 18 <span>〉</span></td><td class="result passed">통과 (0.16ms, 3.89MB)</td></tr></tbody></table><div class="console-message">효율성  테스트</div><table class="console-test-group" data-category="effectiveness"><tbody><tr data-testcase-id="22296"><td valign="top" class="td-label">테스트 1 <span>〉</span></td><td class="result passed">통과 (12.97ms, 10.4MB)</td></tr><tr data-testcase-id="22297"><td valign="top" class="td-label">테스트 2 <span>〉</span></td><td class="result passed">통과 (14.70ms, 10.2MB)</td></tr><tr data-testcase-id="22298"><td valign="top" class="td-label">테스트 3 <span>〉</span></td><td class="result passed">통과 (18.08ms, 10.1MB)</td></tr></tbody></table><div class="console-heading">채점 결과</div><div class="console-message">정확성: 85.7</div><div class="console-message">효율성: 14.3</div><div class="console-message">합계: 100.0 / 100.0</div></pre></div>
              



  <div class="challengeable-banner-wrapper result-banner" style="position:relative;width:100%;margin-bottom: 21px;">
    <a href="https://school.programmers.co.kr/learn/courses/20814" target="_blank" style="width:100%;display:flex;justify-content:center;" data-hackle-value="{&quot;key&quot;:&quot;school_challenge_coderun_banner_clicked&quot;,&quot;properties&quot;:{&quot;course_id&quot;:30,&quot;lesson_id&quot;:12987,&quot;banner_id&quot;:6997,&quot;challenge_title&quot;:&quot;숫자 게임&quot;,&quot;challenge_level&quot;:3,&quot;challenge_category&quot;:&quot;algorithm&quot;}}">
      <img src="https://grepp-programmers.s3.amazonaws.com/production/file_resource/5714/KDT-full_stackcodingtest_banner_tablet__1456x180_.png" alt="프로그래머스 K-Digital Training" style="width:100%; max-width:728px;">
    </a>
  </div>

          </div>

          <div id="ai" class="ai-output tab-pane fade in show" role="tabpanel" aria-labelledby="output-tab">
            <div class="intro">
              <div class="title">내가 제출한 코드가 왜 틀렸는지 프로그래머스 AI에게 물어보세요.</div>
              <div class="note"><svg class="ic-14"><use xlink:href="/assets/svg-defs-bfd029363f2c8bdfe15e5ec48b70c852adde08037cfa9a9ab8024207254aaa7d.svg#ic-info"></use></svg> 제출 후 채점하기를 눌러 30점 이상인 경우 물어볼 수 있어요.<br> 베타 기간 동안에는 한 문제당 1번만 물어볼 수 있어요.</div>
            </div>
          </div>
      </div>
    </div>
  </div>
</div>


<div class="button-section">
  <div class="testcase-button">
      <a id="btn-show-question" class="btn btn-dark" href="/learn/courses/30/lessons/12987/questions">질문하기 (22)</a>
        <a class="btn btn-dark btn-block" data-remote="true" href="/challenge_algorithms/1412/custom_testcases?lesson_id=12987">
          테스트 케이스 추가하기
</a>  </div>

  <div class="func-buttons">
      <a id="view-solution-group" class="btn btn-dark btn-svg" data-remote="true" href="/learn/courses/30/lessons/12987/solution_groups?language=cpp">
         <span>다른 사람의 풀이</span>
</a>
      <a id="reset-code" class="btn btn-dark" data-trigger="hover" data-toggle="popover" data-placement="top" data-content="에디터의 코드가 초기화됩니다. 초기화 버튼을 누르기 이전 코드 복원하려면 코드 에디터에 커서를 두고 Ctrl-Z를 눌러 보세요." href="#" data-original-title="" title="">초기화</a>
      <div id="tour4" data-hackle-value="{&quot;key&quot;:&quot;school_challenge_coderun_clicked&quot;,&quot;properties&quot;:{&quot;course_id&quot;:30,&quot;lesson_id&quot;:12987,&quot;challenge_title&quot;:&quot;숫자 게임&quot;,&quot;challenge_level&quot;:3,&quot;challenge_category&quot;:&quot;algorithm&quot;}}">
        <button name="button" type="submit" id="run-code" class="btn btn-dark" data-trigger="hover" data-toggle="popover" data-placement="top" data-content="작성한 코드를 제출하기 전에 먼저 실행해볼 수 있습니다. 예시 테스트 케이스를 사용하며, [테스트 케이스 추가하기]를 눌러 원하는 테스트 케이스를 추가할 수 있습니다." data-original-title="" title="">코드 실행</button>
      </div>

        <div id="tour5">
          <button name="button" type="submit" id="submit-code" class="btn btn-primary" data-trigger="hover" data-toggle="popover" data-placement="top" data-content="시험 종료 전까지 언제든 다시 제출할 수 있으며, 제출한 코드 중 가장 높은 점수를 낸 코드가 최종 답안이 됩니다." data-original-title="" title="">제출 후 채점하기</button>
        </div>
  </div>
</div>

</div>