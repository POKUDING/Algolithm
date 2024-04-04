<div class="guide-section" style="width: calc(40% - 12px);">
    <div class="tab-pane fade active show" id="tour2">
      <div class="guide-section-description">
        <h6 class="guide-section-title">문제 설명</h6>
        <div class="markdown solarized-dark"><h2>오픈채팅방</h2>

<p>카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데, 본래 닉네임이 아닌 가상의 닉네임을 사용하여 채팅방에 들어갈 수 있다.</p>

<p>신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 다양한 사람들이 들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다. 채팅방에 누군가 들어오면 다음 메시지가 출력된다.</p>

<p>"[닉네임]님이 들어왔습니다."</p>

<p>채팅방에서 누군가 나가면 다음 메시지가 출력된다.</p>

<p>"[닉네임]님이 나갔습니다."</p>

<p>채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다.</p>

<ul>
<li>채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.</li>
<li>채팅방에서 닉네임을 변경한다.</li>
</ul>

<p>닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다. </p>

<p>예를 들어, 채팅방에 "Muzi"와 "Prodo"라는 닉네임을 사용하는 사람이 순서대로 들어오면 채팅방에는 다음과 같이 메시지가 출력된다.</p>

<p>"Muzi님이 들어왔습니다."<br>
"Prodo님이 들어왔습니다."</p>

<p>채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.</p>

<p>"Muzi님이 들어왔습니다."<br>
"Prodo님이 들어왔습니다."<br>
"Muzi님이 나갔습니다."</p>

<p>Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.</p>

<p>"Prodo님이 들어왔습니다."<br>
"Prodo님이 들어왔습니다."<br>
"Prodo님이 나갔습니다."<br>
"Prodo님이 들어왔습니다."</p>

<p>채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다. 이제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.</p>

<p>"Prodo님이 들어왔습니다."<br>
"Ryan님이 들어왔습니다."<br>
"Prodo님이 나갔습니다."<br>
"Prodo님이 들어왔습니다."</p>

<p>채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함수를 완성하라.</p>

<h5>제한사항</h5>

<ul>
<li>record는 다음과 같은 문자열이 담긴 배열이며, 길이는 <code>1</code> 이상 <code>100,000</code> 이하이다.</li>
<li>다음은 record에 담긴 문자열에 대한 설명이다.

<ul>
<li>모든 유저는 [유저 아이디]로 구분한다.</li>
<li>[유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - "Enter [유저 아이디] [닉네임]" (ex. "Enter uid1234 Muzi")</li>
<li>[유저 아이디] 사용자가 채팅방에서 퇴장 - "Leave [유저 아이디]" (ex. "Leave uid1234")</li>
<li>[유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - "Change [유저 아이디] [닉네임]" (ex. "Change uid1234 Muzi")</li>
<li>첫 단어는 Enter, Leave, Change 중 하나이다.</li>
<li>각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.</li>
<li>유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.</li>
<li>유저 아이디와 닉네임의 길이는 <code>1</code> 이상 <code>10</code> 이하이다.</li>
<li>채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.</li>
</ul></li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>record</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td><code>["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]</code></td>
<td><code>["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]</code></td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1<br>
문제의 설명과 같다.</p>
</div>
      </div>
    </div>


      <div class="submission-history-list-section tab-pane fade" id="submissionHistory">
        <div class="submission-history-wrapper">


  <div data-challengeable-submission-history-component="submission-history" data-user-id="624683" data-lesson-id="42888" data-current-theme="dark" data-webapp="true" style="width: 100%; height: 100%;"><div class="SubmissionHistorystyle__Container-sc-topbuc-0 iVNFti theme-dark"><div class="SubmissionHistorystyle__ListLayout-sc-topbuc-1 khRHCb"><div class="Headerstyle__Container-sc-xey78k-0 kbsNBj"><div class="Headerstyle__TotalSubmissionCount-sc-xey78k-1 hzNbuo">1개의 제출</div><div class="Headerstyle__RefreshButton-sc-xey78k-4 gaLZyr theme-dark" data-hackle-value="{&quot;key&quot;:&quot;open_challenge_lesson_submission_history_refresh_clicked&quot;,&quot;properties&quot;:{&quot;total_entries&quot;:1,&quot;lesson_id&quot;:42888}}"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="Headerstyle__RefreshIcon-sc-xey78k-2 jbYPfE"><path fill-rule="evenodd" clip-rule="evenodd" d="M19 8L15 12H18C18 15.31 15.31 18 12 18C10.99 18 10.03 17.75 9.2 17.3L7.74 18.76C8.97 19.54 10.43 20 12 20C16.42 20 20 16.42 20 12H23L19 8ZM6 12C6 8.69 8.69 6 12 6C13.01 6 13.97 6.25 14.8 6.7L16.26 5.24C15.03 4.46 13.57 4 12 4C7.58 4 4 7.58 4 12H1L5 16L9 12H6Z" fill="black"></path></svg><span class="Headerstyle__RefreshText-sc-xey78k-3 cNPYye">새로고침</span></div></div><div class="SubmissionListstyle__ListLayout-sc-dysuo0-2 eaCzRc"><div class="SubmissionListstyle__ListHeader-sc-dysuo0-9 eOLKHZ theme-dark"><div class="SubmissionListstyle__ListRow-sc-dysuo0-8 kWkWMs"><div class="SubmissionListstyle__ListItemColumnWrapper-sc-dysuo0-5 jbeaNc"><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt">제출일시</div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt">언어</div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt">채점 내역</div></div></div></div><div class="SubmissionListstyle__ListBody-sc-dysuo0-10 kPkVNv theme-dark"><div data-hackle-value="{&quot;key&quot;:&quot;open_challenge_lesson_submission_history_list_item_toggle_clicked&quot;,&quot;properties&quot;:{&quot;lesson_id&quot;:42888,&quot;created_at&quot;:&quot;2024-04-04T11:36:21.878+09:00&quot;,&quot;language&quot;:&quot;java&quot;,&quot;score&quot;:100,&quot;is_perfect_score&quot;:true}}" class="SubmissionListstyle__ListRow-sc-dysuo0-8 kWkWMs"><div class="SubmissionListstyle__ListItemColumnWrapper-sc-dysuo0-5 jbeaNc theme-dark"><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="SubmissionListstyle__ToggleIcon-sc-dysuo0-4 bYEfRJ"><path d="M20.735 11.1653C21.334 11.5606 21.334 12.4394 20.735 12.8347L7.80074 21.3691C7.13589 21.8078 6.25 21.3309 6.25 20.5344L6.25 3.4656C6.25 2.66905 7.13589 2.19223 7.80074 2.63092L20.735 11.1653Z" fill="black"></path></svg></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><span class="SubmissionListstyle__WhiteText-sc-dysuo0-3 kJJFrt theme-dark">2024-04-04 11:36:21</span></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><span class="SubmissionListstyle__WhiteText-sc-dysuo0-3 kJJFrt theme-dark">Java</span></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><div class="SubmissionListstyle__ScoreInfo-sc-dysuo0-14 CLVpA theme-dark"><svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg" class="SubmissionListstyle__CorrectIcon-sc-dysuo0-12 gGErbe"><g clip-path="url(#clip0_697_1368)"><path d="M8 0C3.6 0 0 3.6 0 8C0 12.4 3.6 16 8 16C12.4 16 16 12.4 16 8C16 3.6 12.4 0 8 0ZM6.3 12L3 8.7L4.4 7.3L6.3 9.2L11.6 3.9L13 5.3L6.3 12Z" fill="black"></path></g><defs><clipPath id="clip0_697_1368"><rect width="16" height="16" fill="white"></rect></clipPath></defs></svg><span class="SubmissionListstyle__ScoreText-sc-dysuo0-11 ghcIpf correct">정답</span></div><div class="SubmissionListstyle__ScoreNumber-sc-dysuo0-15 ivpXjX theme-dark">100 / 100</div></div></div></div></div><div class="PaginationNavstyle__Buttons-sc-isexrc-0 dQnsAP"><button class="PaginationNavstyle__ArrowEnd-sc-isexrc-2 kUZvyN start" aria-label="처음 페이지" disabled=""></button><button class="PaginationNavstyle__Arrow-sc-isexrc-3 jqCdaE prev" aria-label="이전 페이지" disabled=""></button><span class="PaginationNavstyle__PageButtonContainer-sc-isexrc-1 hlKQCf"><button data-testid="page-active" class="PaginationNavstyle__PageButton-sc-isexrc-4 erXNIv">1</button></span><button class="PaginationNavstyle__Arrow-sc-isexrc-3 jqCdaE next" aria-label="다음 페이지" disabled=""></button><button class="PaginationNavstyle__ArrowEnd-sc-isexrc-2 kUZvyN last" aria-label="마지막 페이지" disabled=""></button></div></div></div></div></div>
  <script src="https://d1nuzc1w51n1es.cloudfront.net/2daa8ebbce0e54b0d155.js" defer="defer"></script>
</div>

      </div>
  </div>