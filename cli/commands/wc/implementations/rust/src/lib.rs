pub mod wc {
    use std::env;
    use std::fs::File;
    use std::io::{Error, Read};

    pub fn count_lines(file_content: &String) -> usize {
        return file_content.lines().count();
    }

    pub fn count_bytes(file_content: &String) -> usize {
        return 0
    }

    pub fn count_words(file_content: &String) -> usize {
        return 0
    }

    pub fn get_file_content() -> Result<String, Error> {
        let mut content = String::new();
        let mut file = get_file()?;
        file.read_to_string(&mut content)?;
        Ok(content)
    }

    fn get_file() -> Result<File, Error> {
        let path = get_path();
        let file = File::open(path)?;
        Ok(file)
    }

    fn get_path() -> String {
        let args: Vec<String> = env::args().collect();
        let path_has_been_passed = args.len() > 1;
        let path = if path_has_been_passed {
            args[1].as_str()
        } else {
            DEFAULT_PATH
        };
        String::from(path)
    }

    const DEFAULT_PATH: &'static str = "../../data/text.txt";
}
