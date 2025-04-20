import re
from report_progress import generate_progress_report

with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

new_table = generate_progress_report(no_cache=True)

updated_content = re.sub(
    r"<!-- PROGRESS-TABLE:START -->(.*?)<!-- PROGRESS-TABLE:END -->",
    f"<!-- PROGRESS-TABLE:START -->\n{new_table}\n<!-- PROGRESS-TABLE:END -->",
    content,
    flags=re.DOTALL
)

with open("README.md", "w", encoding="utf-8") as f:
    f.write(updated_content)
