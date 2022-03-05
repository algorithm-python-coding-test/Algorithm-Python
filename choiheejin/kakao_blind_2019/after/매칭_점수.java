// Link 객체 구현
// 기본점수, 외부링크들, 링크 점수, 인덱스를 가지는 Link 클래스
// Url 링크들을 추출하고 word 등장 횟수 계산
package choiheejin.kakao_blind_2019.after;

import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 매칭_점수 {
    class Link {
        String url;
        String[] ext_urls;
        double point, link_point;
        int index;

        public Link(int i, String url) {
            this.index = i;
            this.url = url;
        }

        public void setExtUrls(ArrayList<String> urls) {
            this.ext_urls = new String[urls.size()];
            for (int i = 0; i < urls.size(); i++) {
                ext_urls[i] = urls.get(i);
            }
        }

        public void setLinkPoint() {
            this.link_point = this.point / ext_urls.length;
        }
    }

    HashMap<String, Link> Links;

    public int solution(String word, String[] pages) {
        Links = new HashMap<>();

        Pattern home_url_pattern = Pattern.compile("<meta property=\"og:url\" content=\"(\\S*)\"");
        Pattern url_pattern = Pattern.compile("<a href=\"https://(\\S*)\"");
        Pattern word_pattern = Pattern.compile("\\b(?i)" + word + "\\b");
        Matcher url_matcher, word_matcher, home_url_matcher;

        ArrayList<String> ext_urls;
        Link new_Link;
        String body;
        String home_url = "";

        for (int i = 0; i < pages.length; i++) {
            // 외부링크 추출용 matcher
            url_matcher = url_pattern.matcher(pages[i]);
            // 홈 링크 추출용 matcher
            home_url_matcher = home_url_pattern.matcher(pages[i]);

            // 홈링크 추출
            if (home_url_matcher.find()) {
                home_url = home_url_matcher.group().split("=")[2].replaceAll("\"", "");
            }

            // 해당 웹페이지 링크 객체 생성
            new_Link = new Link(i, home_url);

            // 외부 링크들 채우기
            ext_urls = new ArrayList<>();
            while (url_matcher.find()) {
                ext_urls.add(url_matcher.group().split("\"")[1]);
            }
            new_Link.setExtUrls(ext_urls);

            // 알맞는 단어 세기
            body = pages[i].split("<body>")[1].split("</body>")[0].replaceAll("[0-9]", " ");
            word_matcher = word_pattern.matcher(body);
            int word_cnt = 0;
            while (word_matcher.find())
                word_cnt++;

            // 포인트를 기본 점수로
            new_Link.point = word_cnt;
            // 외부 링크수로 나눠줌
            new_Link.setLinkPoint();

            // 리스트에 해당 링크 저장 (url, Link)
            Links.put(new_Link.url, new_Link);
        }

        // 각 링크에 대하여 외부 링크로 걸고 있던 모든 링크들의 점수 업데이트
        for (Link link : Links.values()) {
            for (String ext_url : link.ext_urls) {
                if (Links.containsKey(ext_url)) {
                    Links.get(ext_url).point += link.link_point;
                }
            }
        }

        // max 값 구하기
        double max_point = 0;
        int answer = 0;
        for (Link link : Links.values()) {
            if (link.point == max_point) {
                if (link.index < answer)
                    answer = link.index;
            } else if (link.point > max_point) {
                answer = link.index;
                max_point = link.point;
            }
        }

        return answer;
    }

}
