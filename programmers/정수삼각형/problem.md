<div class="guide-section" style="width: calc(40% - 12px);">
    <div class="tab-pane fade active show" id="tour2">
      <div class="guide-section-description">
        <h6 class="guide-section-title">문제 설명</h6>
        <div class="markdown solarized-dark"><p><img src="https://grepp-programmers.s3.amazonaws.com/files/production/97ec02cc39/296a0863-a418-431d-9e8c-e57f7a9722ac.png" title="" alt="스크린샷 2018-09-14 오후 5.44.19.png"></p>

<p>위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.</p>

<p>삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.</p>

<h5>제한사항</h5>

<ul>
<li>삼각형의 높이는 1 이상 500 이하입니다.</li>
<li>삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>triangle</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]</td>
<td>30</td>
</tr>
</tbody>
      </table></div>
      </div>
    </div>


      <div class="submission-history-list-section tab-pane fade" id="submissionHistory">
        <div class="submission-history-wrapper">


  <div data-challengeable-submission-history-component="submission-history" data-user-id="624683" data-lesson-id="43105" data-current-theme="dark" data-webapp="true" style="width: 100%; height: 100%;"><div class="SubmissionHistorystyle__Container-sc-topbuc-0 iVNFti theme-dark"><div class="SubmissionHistorystyle__ListLayout-sc-topbuc-1 khRHCb"><div class="Headerstyle__Container-sc-xey78k-0 kbsNBj"><div class="Headerstyle__TotalSubmissionCount-sc-xey78k-1 hzNbuo">1개의 제출</div><div class="Headerstyle__RefreshButton-sc-xey78k-4 gaLZyr theme-dark" data-hackle-value="{&quot;key&quot;:&quot;open_challenge_lesson_submission_history_refresh_clicked&quot;,&quot;properties&quot;:{&quot;total_entries&quot;:1,&quot;lesson_id&quot;:43105}}"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="Headerstyle__RefreshIcon-sc-xey78k-2 jbYPfE"><path fill-rule="evenodd" clip-rule="evenodd" d="M19 8L15 12H18C18 15.31 15.31 18 12 18C10.99 18 10.03 17.75 9.2 17.3L7.74 18.76C8.97 19.54 10.43 20 12 20C16.42 20 20 16.42 20 12H23L19 8ZM6 12C6 8.69 8.69 6 12 6C13.01 6 13.97 6.25 14.8 6.7L16.26 5.24C15.03 4.46 13.57 4 12 4C7.58 4 4 7.58 4 12H1L5 16L9 12H6Z" fill="black"></path></svg><span class="Headerstyle__RefreshText-sc-xey78k-3 cNPYye">새로고침</span></div></div><div class="SubmissionListstyle__ListLayout-sc-dysuo0-2 eaCzRc"><div class="SubmissionListstyle__ListHeader-sc-dysuo0-9 eOLKHZ theme-dark"><div class="SubmissionListstyle__ListRow-sc-dysuo0-8 kWkWMs"><div class="SubmissionListstyle__ListItemColumnWrapper-sc-dysuo0-5 jbeaNc"><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt">제출일시</div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt">언어</div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt">채점 내역</div></div></div></div><div class="SubmissionListstyle__ListBody-sc-dysuo0-10 kPkVNv theme-dark"><div data-hackle-value="{&quot;key&quot;:&quot;open_challenge_lesson_submission_history_list_item_toggle_clicked&quot;,&quot;properties&quot;:{&quot;lesson_id&quot;:43105,&quot;created_at&quot;:&quot;2024-04-04T10:31:02.163+09:00&quot;,&quot;language&quot;:&quot;java&quot;,&quot;score&quot;:100,&quot;is_perfect_score&quot;:true}}" class="SubmissionListstyle__ListRow-sc-dysuo0-8 kWkWMs"><div class="SubmissionListstyle__ListItemColumnWrapper-sc-dysuo0-5 jbeaNc theme-dark"><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="SubmissionListstyle__ToggleIcon-sc-dysuo0-4 bYEfRJ"><path d="M20.735 11.1653C21.334 11.5606 21.334 12.4394 20.735 12.8347L7.80074 21.3691C7.13589 21.8078 6.25 21.3309 6.25 20.5344L6.25 3.4656C6.25 2.66905 7.13589 2.19223 7.80074 2.63092L20.735 11.1653Z" fill="black"></path></svg></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><span class="SubmissionListstyle__WhiteText-sc-dysuo0-3 kJJFrt theme-dark">2024-04-04 10:31:02</span></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><span class="SubmissionListstyle__WhiteText-sc-dysuo0-3 kJJFrt theme-dark">Java</span></div><div class="SubmissionListstyle__ListColumn-sc-dysuo0-7 jWepvt"><div class="SubmissionListstyle__ScoreInfo-sc-dysuo0-14 CLVpA theme-dark"><svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg" class="SubmissionListstyle__CorrectIcon-sc-dysuo0-12 gGErbe"><g clip-path="url(#clip0_697_1368)"><path d="M8 0C3.6 0 0 3.6 0 8C0 12.4 3.6 16 8 16C12.4 16 16 12.4 16 8C16 3.6 12.4 0 8 0ZM6.3 12L3 8.7L4.4 7.3L6.3 9.2L11.6 3.9L13 5.3L6.3 12Z" fill="black"></path></g><defs><clipPath id="clip0_697_1368"><rect width="16" height="16" fill="white"></rect></clipPath></defs></svg><span class="SubmissionListstyle__ScoreText-sc-dysuo0-11 ghcIpf correct">정답</span></div><div class="SubmissionListstyle__ScoreNumber-sc-dysuo0-15 ivpXjX theme-dark">100 / 100</div></div></div></div></div><div class="PaginationNavstyle__Buttons-sc-isexrc-0 dQnsAP"><button class="PaginationNavstyle__ArrowEnd-sc-isexrc-2 kUZvyN start" aria-label="처음 페이지" disabled=""></button><button class="PaginationNavstyle__Arrow-sc-isexrc-3 jqCdaE prev" aria-label="이전 페이지" disabled=""></button><span class="PaginationNavstyle__PageButtonContainer-sc-isexrc-1 hlKQCf"><button data-testid="page-active" class="PaginationNavstyle__PageButton-sc-isexrc-4 erXNIv">1</button></span><button class="PaginationNavstyle__Arrow-sc-isexrc-3 jqCdaE next" aria-label="다음 페이지" disabled=""></button><button class="PaginationNavstyle__ArrowEnd-sc-isexrc-2 kUZvyN last" aria-label="마지막 페이지" disabled=""></button></div></div></div></div></div>
  <script src="https://d1nuzc1w51n1es.cloudfront.net/2daa8ebbce0e54b0d155.js" defer="defer"></script>
</div>

      </div>
  </div>