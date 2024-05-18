import os

# ANSI颜色码
class Color:
    YELLOW = '\033[93m'
    CYAN = '\033[96m'
    END = '\033[0m'

def main():
    # 获取当前文件所在目录
    current_dir = os.path.dirname(os.path.abspath(__file__))

    # 获取父级目录
    parent_dir = os.path.dirname(current_dir)

    folder_path = os.path.join(parent_dir, "example/example_new")
    response = input(f'which name do you want to use for the new example? (default: example_new, press "Enter" to continue): ')
    if response:
        folder_path = os.path.join(parent_dir, f'example/{response}')
        
    if os.path.isdir(folder_path):
        response = input( f"Directory {folder_path} already exists. "+ Color.YELLOW + "Do you want to overwrite it? (y/n): " + Color.END)
        if response.lower() != "y":
            print("Aborted.")
            return

    print("Generating new example in " + Color.CYAN + f'{folder_path}' + Color.END)
    os.system(f"cp -r {parent_dir}/example/template {folder_path}")
    os.system(f"sudo chmod -R 777 {folder_path}")
    print("Copy operation completed successfully.")

if __name__ == "__main__":
    main()