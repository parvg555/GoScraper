package main

//make curly braces paranthesis
import (
	"fmt"
	"net/http"
	"os"
	"strings"

	"github.com/PuerkitoBio/goquery"
	)
// this is changes

func dis(url string) ([]string, []string, []string) {
	// making a url request
	//write err instead of _
	resp, err := http.Get(url)

	if err != nil {
		fmt.Println("fail1")
		os.Exit(3)
	}
	//closing my request
	defer resp.Body.Close()

	// goquery doc
	doc, _ := goquery.NewDocumentFromReader(resp.Body)

	// creating array for diseases
	var d []string
	var l []string
	var p []string
	var class string
	doc.Find(".unstyled-list").Each(func(_ int, s *goquery.Selection) {
		s.Find("li").Each(func(_ int, t *goquery.Selection) {
			t.Find("a").Each(func(_ int, p *goquery.Selection) {
				class, _ = p.Attr("class")

			})
			// class, _ := t.Attr("class")
			if class == "" {
				t.Find("a").Each(func(_ int, q *goquery.Selection) {
					newURL, _ := q.Attr("href")
					h, parv := branchone(newURL)
					l = append(l, h...)
					p = append(p, parv...)
				})
				text := t.Text()
				text2 := strings.Split(fmt.Sprint(text), "—")
				text3 := fmt.Sprint(text2[0])
				// fmt.Println(text3)

				dis := text3 + "|"
				// l = append(l, gog(text3))
				d = append(d, dis)
			}
		})
	})

	return d, l, p
}
func caller() ([]string, []string, []string) {
	a := "b"
	link := "https://www.cdc.gov/diseasesconditions/az/" + a + ".html"
	d, f, l := dis(link)
	return d, f, l
}

//function to further branch and extract data
func branch(url string) []string {
	var data []string
	resp, err := http.Get(url)

	if err != nil {
		return data
	}

	defer resp.Body.Close()

	doc, _ := goquery.NewDocumentFromReader(resp.Body)

	
	doc.Find(".syndicate").Each(func(_ int, p *goquery.Selection) {
		p.Find(".row").Each(func(_ int, q *goquery.Selection) {
			q.Find("ul").Each(func(_ int, g *goquery.Selection) {
				_, c := g.Attr("class")

				if c == true {
					g.SetText("")
				}
			})
			q.Find("h4").Each(func(_ int, f *goquery.Selection) {
				f.SetText("")
			})
			q.Find("h3").Each(func(_ int, r *goquery.Selection) {
				str := "--" + r.Text()
				r.SetText(str)
			})
			q.Find(".card-header").Each(func(_ int, s *goquery.Selection) {
				s.SetText("")
			})
			data = append(data, strings.TrimSpace(fmt.Sprint(q.Text())))

		})
	})

	return data

}

func branchone(url string) ([]string, []string) {
	var re []string
	var links []string
	resp, err := http.Get(url)

	if err != nil {
		fmt.Println("fail3")
		os.Exit(3)
	}

	defer resp.Body.Close()

	doc, _ := goquery.NewDocumentFromReader(resp.Body)

	doc.Find(".syndicate").Each(func(_ int, p *goquery.Selection) {
		p.Find(".row").Each(func(_ int, q *goquery.Selection) {
			q.Find("ul").Each(func(_ int, g *goquery.Selection) {
				_, c := g.Attr("class")

				if c == true {
					g.SetText("")
				}
			})
			q.Find("h4").Each(func(_ int, f *goquery.Selection) {
				f.SetText("")
			})
			q.Find("h3").Each(func(_ int, r *goquery.Selection) {
				str := "--" + r.Text()
				r.SetText(str)
			})
			q.Find(".col-md-4").Each(func(_ int, np *goquery.Selection) {
				np.Find("a").Each(func(_ int, nwr *goquery.Selection) {
					attr, _ := nwr.Attr("href")

					// j := branch(attr)
					links = append(links, attr)
					nwr.SetText("")
				})
			})
			q.Find(".card-header").Each(func(_ int, s *goquery.Selection) {
				s.SetText("")
			})
			q.Find(".card-title").Each(func(_ int, sp *goquery.Selection) {
				sp.SetText("")
			})
			q.Find(".card-body").Each(func(_ int, n *goquery.Selection) {
				n.SetText("")
			})
			q.Find(".card").Each(func(_ int, gq *goquery.Selection) {
				gq.SetText("")
			})
			q.Find(".text-right").Each(func(_ int, nf *goquery.Selection) {
				nf.SetText("")
			})
			yy := strings.TrimSpace(fmt.Sprint(q.Text()))
			re = append(re, yy)

		})
	})
	return re, links
}

//function for google query
// func gog(name string) string {
// 	newname := strings.Split(name, " ")
// 	url := "http://www.google.com/search?q=symptoms+of+"
// 	for i := 0; i < len(newname); i++ {
// 		url = url + newname[i] + "+"
// 	}
// 	fmt.Println(url)
// 	resp, err := http.Get(url)
// 	if err != nil {
// 		os.Exit(3)
// 	}
// 	// fmt.Println(resp)
// 	//closing the request
// 	defer resp.Body.Close()

// 	//goquery doc
// 	doc, _ := goquery.NewDocumentFromReader(resp.Body)
// 	fmt.Println(doc)
// 	//creating array for symptoms
// 	var symp []string
// 	doc.Find(".col").Each(func(_ int, p *goquery.Selection) {
// 		fmt.Println("found a col")
// 		symp = append(symp, p.Text())
// 	})

// 	s := fmt.Sprint(symp)

// 	return s
// }
func newfunc(t []string) []string {
	var a []string
	for i := 0; i < len(t); i++ {
		h := branch(t[i])
		a = append(a, h...)
	}
	return a
}
func main() {
	a, b, c := caller()
	d := newfunc(c)
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(d)
}
