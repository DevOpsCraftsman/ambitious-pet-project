pub mod wc {
    use rust::wc::{
        count_bytes,
        count_lines,
        count_words,
        get_file_content,
    };

    pub fn main() -> std::io::Result<()> {
        let file_content = get_file_content()?;
        count_lines(&file_content);
        count_words(&file_content);
        count_bytes(&file_content);
        Ok(())
    }
}

fn main() {
    wc::main().expect("Not able to open the file");
}
