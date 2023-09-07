pub mod uniq {
    use std::ops::Add;

    pub fn uniq(content: &str) -> String {
        let lines = content.lines();
        if lines.count() <= 1 {
            return String::from(content)
        }
        let mut output = String::from("");
        let result = content.lines()
            .zip(content.lines().skip(1))
            .inspect(|(a, b)| println!("a: {}, b: {}", a, b))
            .collect::<Vec<_>>();
        let mut first_loop = true;
        for (line1, line2) in result {
            if first_loop {
                output = output.add(line1)
            }
            if line1 != line2 {
                output = output.add("\n").add(line2);
            }
        }
        return output;
    }
}
